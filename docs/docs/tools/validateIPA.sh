#!/bin/sh
##
## This script checks various requirements for the BeaconForStore SDK 
## Usage: ./valideIPA.sh <path-to-your-ipa>
##################


# CONSTANTS

VERT="\\033[1;32m"
NORMAL="\\033[0;39m"
ROUGE="\\033[1;31m"
ROSE="\\033[1;35m"
BLEU="\\033[1;34m"
BLANC="\\033[0;02m"
BLANCLAIR="\\033[1;08m"
JAUNE="\\033[1;33m"
CYAN="\\033[1;36m"
UNDERLINE="\\033[4m"

B4S_BUNDLE_NAME="BeaconForStoreStorage.bundle"

TEST_COUNT=1
# Print usage and exit
function		usage {
	echo "This tools checks your IPA against various B4S SDK requirements"
	echo "Usage: ./valideIPA.sh <path-to-your-ipa>"
	exit
}

# Extract app from zip and return path to .app
function		extractIPA {
	#echo "DA PATH: ${1}"
	UUID=`uuidgen`
	EXTRACT_PATH="${TMPDIR}/${UUID}"
	
	mkdir -p "${EXTRACT_PATH}"
	unzip -d "${EXTRACT_PATH}"	"${1}" &> /dev/null 
	
	APP_LIST=`find "${EXTRACT_PATH}" -name "*.app"`
	
	echo "${APP_LIST}"
}

# Get app executable path as an absolute path
function		getExecutablePath {
	APP_PATH="${1}"
	PLIST_PATH="${APP_PATH}/Info.plist"
	EXECUTABLE_NAME=`defaults read ${PLIST_PATH} CFBundleExecutable`
	echo "${APP_PATH}/${EXECUTABLE_NAME}"
}

# Print the test name, underlined 
function	printTestName {
	echo "\n\n${UNDERLINE}" "${TEST_COUNT}/ ${1}:" "$NORMAL"
	let TEST_COUNT=${TEST_COUNT}+1
}

# Print test error, with color
# $1: error message show in red
# $2: extra details to help the user
function	printTestError {
	echo "\t${ROUGE} $1${NORMAL} ${2}"
}

# Print $1 in green with a line return
function	printTestSuccess {
	echo "${VERT}" "${1}\n" "${NORMAL}${2}"
}


if [ -z "$1" ]; then
	printTestError "Missing path to IPA"
	usage
fi


if [ ! -f "$1" ]; then
	printTestError "IPA does not exists at path ${1}" 
	usage
fi


# Compute paths
APP_PATH=$(extractIPA "${1}")
echo "${JAUNE}" "App is extracted to ${APP_PATH}${NORMAL}"

PLIST_PATH="${APP_PATH}/Info.plist"
B4S_BUNDLE_PATH="${APP_PATH}/${B4S_BUNDLE_NAME}"

EXECUTABLE_PATH=$(getExecutablePath "${APP_PATH}")
# Tests

##########################################
# 1/ Storage bundle is present

printTestName "${B4S_BUNDLE_NAME} is present in .app"

if [ ! -d ${B4S_BUNDLE_PATH} ]; then
	printTestError "Missing file" "Please refer to the document 'Integrating the SDK with your Xcode project' > 'Import BeaconForStoreStorage.bundle'"
else
	 printTestSuccess "OK"
fi

###########################################
# 2/ All required frameworks are present


declare -a frameworks=(AVFoundation.framework CoreBluetooth.framework CoreData.framework CoreLocation.framework CoreMotion.framework MobileCoreServices.framework Security.framework SystemConfiguration.framework UIKit.framework CoreBluetooth.framework CoreLocation.framework)

printTestName "Required frameworks are linked with executable"

OTOOL_L_OUTPUT=`otool -L  ${EXECUTABLE_PATH}`
HAS_ERROR="NO"

for var in "${frameworks[@]}"
do
  if [[ ! ${OTOOL_L_OUTPUT} == *"${var}"* ]]; then
	  printTestError "Framework ${var} is missing" "Please refer to the document 'Integrating the SDK with your Xcode project' > 'Import frameworks'"
	  HAS_ERROR="YES"
  fi
done

if [ "${HAS_ERROR}" == "NO" ]; then
	printTestSuccess "OK"
fi

###########################################
# 3/ B4S symbols exists in the binary

printTestName "Beacon4Store framework is linked with executable"

NM_OUTPUT=`strings "${EXECUTABLE_PATH}"`
if [[ ! ${NM_OUTPUT} == *"B4SSingleton"* ]]; then
  printTestError "The Beacon4Store SDK was not linked with your executable" "Please refer to the document 'Integrating the SDK with your Xcode project' > 'Import frameworks'"
else
	printTestSuccess "OK"
fi

###########################################
# 4/ Key NSLocationAlwaysUsageDescription is present in Info.plist

printTestName "Key NSLocationAlwaysUsageDescription exists in Info.plist"

ALWAYS_USAGE_DESCRIPTION=`defaults read "${PLIST_PATH}" NSLocationAlwaysUsageDescription &> /dev/null `

if [ "$?" -eq  1 ]; then
    printTestError "The key NSLocationAlwaysUsageDescription is missing from Info.plist" "Please refer to the document 'Integrating the SDK with your Xcode project' > 'Allow location usage'"
else
  	printTestSuccess "OK" "Value is \"${ALWAYS_USAGE_DESCRIPTION}\""
	if [ ! -n "${ALWAYS_USAGE_DESCRIPTION}" ]; then
		echo "Warning: This key should not be empty. See https://developer.apple.com/library/ios/documentation/General/Reference/InfoPlistKeyReference/Articles/CocoaKeys.html#//apple_ref/doc/uid/TP40009251-SW18 for more information"
	fi
fi

###########################################
# Background modes in Info.plist
 
printTestName "Background fetch is enabled"
BACKGROUND_MODES=`defaults read "${PLIST_PATH}" UIBackgroundModes &> /dev/null `

if [[ ! ${NM_OUTPUT} == *"fetch"* ]]; then
    printTestError "The Backgroud mode 'fetch' in not enable. " "Please refer to the document 'Integrating the SDK with your Xcode project' > 'Configure application modes'"
else
  	printTestSuccess "OK"
fi
