## Requirements

the B4S SDK uses Bluetooth 4.0 BLE (Bluetooth Low Energy) and will only be available on **iPhone 4S** devices and up.
- Minimum iOS target : iOS 7
- Xcode 5 is required

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
- CoreBluetooth.framework
- CoreLocation.framework
- AVFoundation.framework
- Security.framework
- CodeData.framework
- MobileCoreService.framework
- SystemConfiguration.framework
- CoreMotion.framework
- UIKit.framework
- libc++.dylib


## Usage

### Configure the SDK

- Import the Framework in your appDelegate.h file
```objective-c
#import <BeaconForStoreSDK/BeaconForStoreSDK.h>
```
- Set the B4S delegate
```objective-c
@interface AppDelegate : UIResponder <UIApplicationDelegate,B4SDelegate>
```
- Initialize the Framework in the applicationDidFinishLaunching method
```objective-c
Add an observer for the B4S SDK notification processed event.
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(notificationProcessed:) name:kB4SNotificationProcessedNotification object:nil];

//replace MY-APP-ID with the ID associated to your beacon4store account
B4SSingleton *b4sSingleton = [B4SSingleton setupSharedInstanceWithAppId:@"MY-APP-ID" adminMode:NO];
[b4sSingleton B4SsetPeriodicBeaconsUpdate:NO];
[B4SSingleton sharedInstance].delegate = self;
[[B4SSingleton sharedInstance] startStandAloneMode];

//change this to any other sound if wanted. If not specified, a default sound will be played
[b4sSingleton setNotificationSoundname:@"sound.caf"];
```

### Enable bluetootk on iOS8

Starting with iOS8, in order to use bluetooth with iBeacons, you had to specify these key : NSLocationAlwaysUsageDescription with a String which describe your usage of iBeacon. If you don't specify this key, you will not be able to use iBeacons on iOS8 devices.

### Enable background mode

For the SDK to be able to track the beacons even in background mode, you have to enable background modes in your application.
In the project settings -> Capabilities, turn on background Modes and select following modes :
- Background fetch

Be careful, you can add 'Location updates' mode if you want to add long term baground mode. By doing this, your application may be rejected by the AppStore.

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
After notification processing, a kB4SNotificationProcessedNotification event is fired by the SDK. You can extract an actionId whose value is one of :
 - kB4SCONFIGUPDT_INAPP : You set the interaction to open a predefined page in your application. The pageId you set can be retrieve in the userInfo dictionnary.
 - kB4SCONFIGUPDT_INAPPWEB : A webview was opened to display the url set in the interaction
 - kB4SCONFIGUPDT_WEB : An url was open in Safari. Or an Url Scheme.
 - kB4SCONFIGUPDT_REJECT : The user select the 'Cancel' button.
 - kB4SCONFIGUPDT_NONE : No internal action was required.

```objective-c
- (void)notificationProcessed:(UILocalNotification *)notificationData {
    NSLog(@"notificationProcessed : %@",notificationData);
    NSLog(@"[didReceiveLocalNotification] beaconId=%@",[notificationData.userInfo objectForKey:kB4SNotifBeaconId]);
    NSLog(@"[didReceiveLocalNotification] beaconName=%@",[notificationData.userInfo objectForKey:kB4SNotifContentName]);
    NSLog(@"[didReceiveLocalNotification] distance=%@",[notificationData.userInfo objectForKey:kB4SNotifDistance]);
    NSLog(@"[didReceiveLocalNotification] interaction name=%@",[notificationData.userInfo objectForKey:kB4SNotifContentName]);
    NSLog(@"[didReceiveLocalNotification] interaction id=%@",[notificationData.userInfo objectForKey:kB4SNotifContentId]);
    NSLog(@"[didReceiveLocalNotification] text=%@",[notificationData.userInfo objectForKey:kB4SNotifText]);
    NSLog(@"[didReceiveLocalNotification] data=%@",[notificationData.userInfo objectForKey:kB4SNotifData]);
    NSLog(@"[didReceiveLocalNotification] group clientRef=%@",[notificationData.userInfo objectForKey:kB4SNotifGroupRef]);
    NSLog(@"[didReceiveLocalNotification] store clientRef=%@",[notificationData.userInfo objectForKey:kB4SNotifStoreRef]);
    NSLog(@"[didReceiveLocalNotification] beacon clientRef=%@",[notificationData.userInfo objectForKey:kB4SNotifBeaconRef]);
    NSLog(@"[didReceiveLocalNotification] beacon udid=%@",[notificationData.userInfo objectForKey:kB4SBeaconUdid]);
    NSLog(@"[didReceiveLocalNotification] beacon major=%@",[notificationData.userInfo objectForKey:kB4SBeaconMajor]);
    NSLog(@"[didReceiveLocalNotification] beacon minor=%@",[notificationData.userInfo objectForKey:kB4SBeaconMinor]);
    NSLog(@"[didReceiveLocalNotification] actionId=%d",actionId);

    int actionId = [[notificationData.userInfo objectForKey:kB4SNotifActionId] intValue];
    if(actionId == kB4SCONFIGUPDT_INAPP) {
        NSString *pageId = [notificationData.userInfo objectForKey:kB4SNotifPageId];
        NSLog(@"inapp pageId : %@",pageId);
        // Open the application UIView associated to the pageId value
    } else if(actionId == kB4SCONFIGUPDT_REJECT) {
        // An alertview was set, but the user select the 'Cancel' button. Nothing to do.
    }
}

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