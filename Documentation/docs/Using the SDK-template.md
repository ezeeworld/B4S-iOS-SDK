## Import the umbrella header In your AppDelegate.h (Objective-C only) :

	#import <BeaconForStoreSDK/BeaconForStoreSDK.h>
	
## Import the Framework in your Bridging-Header.h file (Swift only)

	#import <BeaconForStoreSDK/BeaconForStoreSDK.h>
	
## Implement B4SDelegate in your app delegate (Objective-C only)

	@interface AppDelegate : UIResponder <UIApplicationDelegate,B4SDelegate>	

## Initialize the Framework in the application:didFinishLaunchingWithOptions: method:

Objective-C:

	//Add an observer for the B4S SDK notification processed event.
	[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(notificationProcessed:) name:kB4SNotificationProcessedNotification object:nil];

	//Replace MY-APP-ID with the ID associated with your BeaconForStore account
	B4SSingleton *b4sSingleton = [B4SSingleton setupSharedInstanceWithAppId:@"MY-APP-ID" adminMode:NO];
	[b4sSingleton B4SsetPeriodicBeaconsUpdate:NO];
	[B4SSingleton sharedInstance].delegate = self;
	[[B4SSingleton sharedInstance] startStandAloneMode];

	// Use this method to change the sound played when you app shows a notification to the user
	// The sound file must be in .caf (Core Audio File) format and imported into your project
	[b4sSingleton setNotificationSoundname:@"sound.caf"];


Swift:

	//Add an observer for the B4S SDK notification processed event.
	NSNotificationCenter.defaultCenter().addObserver(self, selector: "notificationProcessed:", name: kB4SNotificationProcessedNotification, object: nil)
	
	//Replace MY-APP-ID with the ID associated to your beacon4store account
	let b4sSingleton = B4SSingleton.setupSharedInstanceWithAppId("MY-APP-ID")
	B4SSingleton.sharedInstance().delegate = self;
	B4SSingleton.sharedInstance().startStandAloneMode()
	
	// Use this method to change the sound played when you app shows a notification to the user
	// The sound file must be in .caf (Core Audio File) format and imported into your project
	b4sSingleton.notificationSoundname = "sound.caf"




## Decoding notifications

The SDK uses local notifications to establish communication between beacons and the app.

Implement the application:didReceiveLocalNotification: method in your appDelegate. A notification will be sent by the SDK when a notification is fired. You can use the UILocalNotification.userInfo to process the notification yourself. But if you set up some automatic action in the B4S setup application, you must call the [B4SSingleton notificationFeedback:] method. So, the SDK will display a confirmation panel (if any) and process one of the requested predefined actions.

Objective-C:

	- (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification
	{
	    NSLog(@"[didReceiveLocalNotification] %@ / %@",[notification.userInfo objectForKey:kB4SNotifBeaconId],[notification.userInfo objectForKey:kB4SNotifContentName]);
	    NSLog(@"notification : %@",notification.description);
	    self.lastNotification = notification;
	
	    // If you want to use B4S SDK internal notification processing (UIAlertView, UIWebView, open Url in Safari, ...), you must call
	    // the B4SSingleton:notificationFeedback: method.
	    [[B4SSingleton sharedInstance] notificationFeedback:notification.userInfo];
	}


Swift:

	func application(application: UIApplication, didReceiveLocalNotification notification: UILocalNotification) {
	{
	    println("[didReceiveLocalNotification] \(notification.userInfo?[kB4SNotifBeaconId]) / \(notification.userInfo?[kB4SNotifContentName)")
	    println("notification : \(notification.description)");
	
	    // If you want to use B4S SDK internal notification processing (UIAlertView, UIWebView, open Url in Safari, ...), you have to call
	    // the B4SSingleton:notificationFeedback: method.
	    B4SSingleton.sharedInstance().notificationFeedback(notification.userInfo?)
	    // After post processing made through the notificationFeedback method, the delegate:notificationProcessed will be called.
	}


After processing a notification, a kB4SNotificationProcessedNotification event is fired by the SDK. The notification type is a B4SActionType that you can get using [[notificationData.userInfo objectForKey:kB4SNotifActionId] intValue]

## Record user data

B4S can relate beacon interactions tot individual customers. Supplying the customer details is typically done on startup and/or after a user signed in to his/her account. In these cases you can update te SDK with this customer data (which is persisted; no need to call every time) using the [B4SSingleton setUserName:firstName:gender:email:customerRef:]

## Application tagging

You can tag your application with the B4S SDK. You can set two values : The first parameter is the event descriptor and the second the userData asociated to the event.

	[B4STag event:@"Test" userData:@"test"];

## B4S Behaviours

This feature allows you to automatically warn the user if Bluetooth, notifications or geolocation are disabled. This setup **must** be done before initializing the B4S Singleton.

	[B4SBehaviours warnForBluetooth:true after:0 count:2 andEvery:2 withTitle:@"Bluetooth" andText:@"Bluetooth is disabled. Do you want to enabled it ?"];
	[B4SBehaviours warnForGeolocation:true after:3 count:2 andEvery:2 withTitle:@"Geoloc" andText:@"Geolocation is disabled. Do you want to enable it ?"];
	[B4SBehaviours warnForNotifications:true after:1 count:2 andEvery:2 withTitle:@"Notifications " andText:@"Notifications are disabled. You need to activate them in order to use this application."];



## Customize notifications

You can customize the notification messages and data sent to your application by implementing the [B4SDelegate customizeNotificationText:andData:andUserInfo:completion:] method in your appDelegate

Objective-C:

	- (void)customizeNotificationText:(NSString *)aText
	                          andData:(NSString *)aData
	                      andUserInfo:(NSMutableDictionary *)userInfos
	                       completion:(void (^)(NSString *pushText, NSString *pushData, NSMutableDictionary *userInfos))completion {
	    if (completion) {
	        NSLog(@"[customizeNotificationText] set notification text with braces");
	        completion([NSString stringWithFormat:@"[%@]",aText], aData, userInfos);
	    }
	}
	

Swift:

	func customizeNotificationText(aText: String!, andData aData: String!, andUserInfo userInfos: NSMutableDictionary!, completion: ((String!, String!, NSMutableDictionary!) -> Void)!) {
	    if completion != nil {
	        println("[customizeNotificationText] set notification text with braces")
	        completion("[\(aText)]", aData, userInfos)
	    }
	}