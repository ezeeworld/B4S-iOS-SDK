# Summary

Including the B4S SDK in your application increases it size about 1.7 MB (as of SDK 1.8.3)

# SDK size

The SDK is distributed as a .framework that contains a static library. This library is pretty heavy as it includes:

 * compiled code for 4 CPU architectures  (armv7 & arm64 for actual devices, i386 & X86_64 for simulators)
 * debug symbols
 * <a href="https://developer.apple.com/library/tvos/documentation/IDEs/Conceptual/AppDistributionGuide/AppThinning/AppThinning.html#//apple_ref/doc/uid/TP40012582-CH35-SW2">Bitcode</a> 

Including all those elements allows:

 * one SDK distribution for all architectures
 * creation of proper dSym files for use with tools such as Crashlytics
 * use of Bitcode features


	The SDK with / without those features would be:

|  SDK size in MB   | With bitcode | Without bitcode |
|--------------|--------------|-----|
| *With debug symbols*   | 23           | 8,5 |
| *Without debug symbol*   | 17,4         | 8,3 |



We can see that most of the bloat is from the inclusion of bitcode, that is an [intermediate representation](http://llvm.org/docs/BitCodeFormat.html#overview) that enables to generate code for any CPU architecture 

# Application size

When compiling an app that includes the B4S SDK, only the necessary architectures are included in the binary: for instance when generating an app for the App Store the i386 et X86_64 architectures are not included.

Since Xcode 7 and iOS 9 the size of the .app generated by Xcode bears little relation with the size of the app that will be downloaded by the user because of the inclusion of bitcode. 
When downloading the app:

 * The bitcode is never included
 * If the device is running iOS 8 or below both architecture are downloaded (armv7 _and_ arm64)
 * If the device is running iOS 9 only the current device architecture is downloaded (armv7 _or_ arm64)

Source: https://forums.developer.apple.com/thread/17903#57206

# Measured application size

To simulate those various sizes we created a minimalistic Xcode project with only the default files

 * Minimal iOS app, without B4S SDK: 238 KB
 * This app + B4S SDK, with all Xcode settings to default:  6.948 MB
 * This app + B4S SDK + "Enabled bitcode" set to No: 1.912 MB (this simulate the size of the app download by a iOS 8 user)
 * This app + B4S SDK + "Enabled bitcode" set to No + "ARCHS" set to "arm64": 1.176 MB (this simulate the size of the app download by a iOS 9 user running an iPhone 5s or more recent )