## Requirements

the B4S SDK uses Bluetooth 4.0 BLE (Bluetooth Low Energy) and will only be available on **iPhone 4S** devices and up.
- Minimum iOS target : iOS 7
- Xcode 6 is required

## Installation

### Add framework
1. Open your application in Xcode
2. Go to Project Settings -> Build Phases. Select « + » in the « link Binary with Libraries » menu
then select « add other » and select **BeaconForStoreSDK.framework**

### B4S files
Add following files to your project : 
- BeaconForStoreStorage.bundle
- sound.caf : this file can be replaced with any other sound you'd like to display in your app

### Additional Frameworks
The following additional frameworks are required :
- CoreBluetooth.framework (Should be declared as optional)
- CoreLocation.framework (Should be declared as optional)
- AVFoundation.framework
- Security.framework
- CodeData.framework
- MobileCoreService.framework
- SystemConfiguration.framework
- CoreMotion.framework
- UIKit.framework

## New in 1.4.4
- Change support for notification on Apple Watch

## New in 1.4.0
- Added new virtual beacon feature
- Added enhanced tracking metrics

## New in 1.3.0
- Made some interface change for swift support

## New in 1.2.0
- Fastest sdk initialization
- Fastest iBeacon detection

## New in 1.1.50
- iBeacon calibration scheme updated
- New shop in/out detection scheme
- Suppressed c++ stuff
- Enhanced iBeacon configuration setup
- Fix battery level setup.
- added -setBluetoothWarnStatus method

## New in 1.1.8
- Added Full time support for notification activation start and end time.

## New in 1.1.7
- Notifications are sent more efficiently when application is in background mode and when application is wake up by iOS.
- InApp webview design was slightly modified.
- New functionnalities matching the new B4S Setup application.

## Usage

### Configure the SDK

- Import the Framework in your appDelegate.h file
```objective-c
#import <BeaconForStoreSDK/BeaconForStoreSDK.h>
```
- Import the Framework in your Bridging-Header.h file
```swift
#import <BeaconForStoreSDK/BeaconForStoreSDK.h>
```
- Set the B4S delegate
```objective-c
@interface AppDelegate : UIResponder <UIApplicationDelegate,B4SDelegate>
```
- Initialize the Framework in the applicationDidFinishLaunching method
```objective-c
//Add an observer for the B4S SDK notification processed event.
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(notificationProcessed:) name:kB4SNotificationProcessedNotification object:nil];

//Replace MY-APP-ID with the ID associated to your beacon4store account
B4SSingleton *b4sSingleton = [B4SSingleton setupSharedInstanceWithAppId:@"MY-APP-ID" adminMode:NO];
[b4sSingleton B4SsetPeriodicBeaconsUpdate:NO];
[B4SSingleton sharedInstance].delegate = self;
[[B4SSingleton sharedInstance] startStandAloneMode];

//change this to any other sound if wanted. If not specified, a default sound will be played
[b4sSingleton setNotificationSoundname:@"sound.caf"];
```
```swift
//Add an observer for the B4S SDK notification processed event.
NSNotificationCenter.defaultCenter().addObserver(self, selector: "notificationProcessed:", name: kB4SNotificationProcessedNotification, object: nil)

//Replace MY-APP-ID with the ID associated to your beacon4store account
let b4sSingleton = B4SSingleton.setupSharedInstanceWithAppId("MY-APP-ID")
B4SSingleton.sharedInstance().delegate = self;
B4SSingleton.sharedInstance().startStandAloneMode()

//change this to any other sound if wanted. If not specified, a default sound will be played
b4sSingleton.notificationSoundname = "sound.caf"
```

### Enable bluetooth on iOS8

Starting with iOS8, in order to use bluetooth with iBeacons, you had to specify these key : NSLocationAlwaysUsageDescription with a String which describe your usage of iBeacon. If you don't specify this key, you will not be able to use iBeacons on iOS8 devices.

### Enable background mode

For the SDK to be able to track the beacons even in background mode, you have to enable background modes in your application.
In the project settings -> Capabilities, turn on background Modes and select following modes :
- Background fetch

### Decode notifications

The SDK uses local notifications to establish communication between beacons and the app.

Implement the  application:didReceiveLocalNotification: method in your appDelegate. A notification will be sent by the SDK when a notification is fired.
You can use the UILocalNotification.userInfo to process yourself the notification. But if you set some automatic action in the B4S setup application, you had to call the B4SSingleton notificationFeedback: method. So, the SDK will display a confirmation panel (if set) and process one of the requested predefined actions.

```objective-c
- (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification
{
    NSLog(@"[didReceiveLocalNotification] %@ / %@",[notification.userInfo objectForKey:kB4SNotifBeaconId],[notification.userInfo objectForKey:kB4SNotifContentName]);
    NSLog(@"notification : %@",notification.description);
    self.lastNotification = notification;

    // If you want to use B4S SDK internal notification processing (UIAlertView, UIWebView, open Url in Safari, ...), you have to call
    // the B4SSingleton::notificationFeedback: method.
    [[B4SSingleton sharedInstance] notificationFeedback:notification.userInfo];
}
```
```swift
func application(application: UIApplication, didReceiveLocalNotification notification: UILocalNotification) {
{
    println("[didReceiveLocalNotification] \(notification.userInfo?[kB4SNotifBeaconId]) / \(notification.userInfo?[kB4SNotifContentName)")
    println("notification : \(notification.description)");
            
    // If you want to use B4S SDK internal notification processing (UIAlertView, UIWebView, open Url in Safari, ...), you have to call
    // the B4SSingleton::notificationFeedback: method.
    B4SSingleton.sharedInstance().notificationFeedback(notification.userInfo?)
    // After post processing made through the notificationFeedback method, the delegate:notificationProcessed will be called.
}
```
After notification processing, a kB4SNotificationProcessedNotification event is fired by the SDK. You can extract an actionId whose value is one of :
 - B4SActionType_INAPP : You set the interaction to open a predefined page in your application. The pageId you set can be retrieve in the userInfo dictionnary.
 - B4SActionType_INAPPWEB : A webview was opened to display the url set in the interaction
 - B4SActionType_WEB : An url was open in Safari. Or an Url Scheme.
 - B4SActionType_REJECT : The user select the 'Cancel' button.
 - B4SActionType_NONE : No internal action was required.

```objective-c
- (void)notificationProcessed:(UILocalNotification *)notificationData {
    NSLog(@"notificationProcessed : %@",notificationData);
    NSLog(@"[notificationProcessed] beaconId=%@",[notificationData.userInfo objectForKey:kB4SNotifBeaconId]);
    NSLog(@"[notificationProcessed] beaconName=%@",[notificationData.userInfo objectForKey:kB4SNotifContentName]);
    NSLog(@"[notificationProcessed] distance=%@",[notificationData.userInfo objectForKey:kB4SNotifDistance]);
    NSLog(@"[notificationProcessed] interaction name=%@",[notificationData.userInfo objectForKey:kB4SNotifContentName]);
    NSLog(@"[notificationProcessed] interaction id=%@",[notificationData.userInfo objectForKey:kB4SNotifContentId]);
    NSLog(@"[notificationProcessed] text=%@",[notificationData.userInfo objectForKey:kB4SNotifText]);
    NSLog(@"[notificationProcessed] data=%@",[notificationData.userInfo objectForKey:kB4SNotifData]);
    NSLog(@"[notificationProcessed] group clientRef=%@",[notificationData.userInfo objectForKey:kB4SNotifGroupRef]);
    NSLog(@"[notificationProcessed] store clientRef=%@",[notificationData.userInfo objectForKey:kB4SNotifStoreRef]);
    NSLog(@"[notificationProcessed] beacon clientRef=%@",[notificationData.userInfo objectForKey:kB4SNotifBeaconRef]);
    NSLog(@"[notificationProcessed] beacon udid=%@",[notificationData.userInfo objectForKey:kB4SBeaconUdid]);
    NSLog(@"[notificationProcessed] beacon major=%@",[notificationData.userInfo objectForKey:kB4SBeaconMajor]);
    NSLog(@"[notificationProcessed] beacon minor=%@",[notificationData.userInfo objectForKey:kB4SBeaconMinor]);
    NSLog(@"[notificationProcessed] actionId=%d",actionId);

    int actionId = [[notificationData.userInfo objectForKey:kB4SNotifActionId] intValue];
    if(actionId == B4SActionType_INAPP) {
        NSString *pageId = [notificationData.userInfo objectForKey:kB4SNotifPageId];
        NSLog(@"inapp pageId : %@",pageId);
        // Open the application UIView associated to the pageId value
    } else if(actionId == B4SActionType_REJECT) {
        // An alertview was set, but the user select the 'Cancel' button. Nothing to do.
    }
}

```
```switft
- (void)notificationProcessed:(UILocalNotification *)notificationData {
    let actionId:B4SActionType = translateIntToB4SActionTypeValue(notificationData.userInfo?[kB4SNotifActionId] as Int);

    if(actionId == .INAPP) {
    	let pageId = notificationData.userInfo?[kB4SNotifPageId] as String;
        println("[notificationProcessed] inapp pageId : \(pageId)");
	// The next value is the shop client own reference set for the shop in B4SManager
        let storeId = notificationData.userInfo?[kB4SNotifStoreRef] as String;
    } else if(actionId == .REJECT) {
        // An alertview was set, but the user select the 'Cancel' button. Nothing to do.
    }
}

```
### Record user data

```objective-c
You can record user data (name, firstname, gender, email, userId) by calling the following method on the singleton
- (void)setUserName:(NSString *)aName
          firstName:(NSString *)aFirstname
             gender:(B4SCustomerGender)aGender
              email:(NSString *)anEmail
        customerRef:(NSString *)aRef;

```

### Customize notifications

You can customize the notification messages and data sent to your application by implementing the customizeNotificationText:andData:andUserInfo:completion: method in your appDelegate

```objective-c
- (void)customizeNotificationText:(NSString *)aText
                          andData:(NSString *)aData
                      andUserInfo:(NSMutableDictionary *)userInfos
                       completion:(void (^)(NSString *pushText, NSString *pushData, NSMutableDictionary *userInfos))completion {
    if(completion) {
        NSLog(@"[customizeNotificationText] set notification text with braces");
        completion([NSString stringWithFormat:@"[%@]",aText], aData, userInfos);
    }
}
```
```swift
func customizeNotificationText(aText: String!, andData aData: String!, andUserInfo userInfos: NSMutableDictionary!, completion: ((String!, String!, NSMutableDictionary!) -> Void)!) {
    if completion != nil {
        println("[customizeNotificationText] set notification text with braces")
        completion("[\(aText)]", aData, userInfos)
    }
}
```