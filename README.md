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
- notif.caf : this file can be replaced with any other sound you'd like to display in your app

### Additional Frameworks
The following frameworks are required :
- AdSupport.framework
- CoreBluetooth.framework
- SystemConfiguration.framework
- CoreMotion.framework
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
//replace MY-APP-ID with the ID associated to your beacon4store account
B4SSingleton *b4sSingleton = [B4SSingleton setupSharedInstanceWithAppId:@"MY-APP-ID" adminMode:NO];
[b4sSingleton B4SsetPeriodicBeaconsUpdate:NO];
[B4SSingleton sharedInstance].delegate = self;
[[B4SSingleton sharedInstance] startStandAloneMode];

//change this to any other sound if wanted
[b4sSingleton setNotificationSoundname:@"notif.caf"];
```

### Set background and foreground interactions

The SDK responds to applicationDidEnterBackground and applicationWillEnterForeground Interactions. Setup these methods in your appDelegate

```objective-c
- (void)applicationDidEnterBackground:(UIApplication *)application
{
	[[B4SSingleton sharedInstance] setBackgroundMode];
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
	[[B4SSingleton sharedInstance] setForegroundMode]; 
}
```

### Decode notifications

The SDK uses local notifications to establish communication between beacons and the app.

Implement the  application:didReceiveLocalNotification: method in your appDelegate

```objective-c
- (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification
{
	NSLog(@"[didReceiveLocalNotification] %@ / %@",[notification.userInfo objectForKey:@"sBeaconId"],[notification.userInfo objectForKey:@"sContentId"]);
	NSLog(@"notification : %@",notification.description);
    
	//send ACK to inform of the notification's reception 
	NSString *ackStr = [NSString stringWithFormat:@"OPEN#%@:%@",[notification.userInfo objectForKey:@"sBeaconId"],[notification.userInfo objectForKey:@"sContentId"]];
	[[B4SSingleton sharedInstance] setAcknowledgeData:ackStr];

	//do what you wish with the notification
	NSString *cancelButtonTitle = NSLocalizedString(@"OK", @"Title for cancel button in local notification");
	UIAlertView *alert = [[UIAlertView alloc] initWithTitle:notification.alertBody message:nil delegate:nil cancelButtonTitle:cancelButtonTitle otherButtonTitles:nil];
	[alert show];
}
```
