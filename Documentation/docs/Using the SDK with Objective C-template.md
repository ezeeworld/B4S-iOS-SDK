Depending on how you use the B4S SDK, some steps are mandatory, some are optional.

 * Base integration for counting visits
 * Recording user data
 * Beacon-based notifications
 * Application tagging
 * Push notifications

# Base integration

The base integration requires the following steps.

 * Import the Framework In your AppDelegate.m

		@import BeaconForStoreSDK;

 *  Initialize and start the SDK in the application:didFinishLaunchingWithOptions: method: 


		//Replace MY-APP-ID with the ID associated with your BeaconForStore account
		[B4SSingleton setupSharedInstanceWithAppId:@"MY-APP-ID"];
		[[B4SSingleton sharedInstance] startStandAloneMode];

# Recording user data

B4S can relate events tot individual customers. Supplying the customer details is typically done on startup and/or after a user signed in to his/her account. In these cases you can update te SDK with this customer data (which is persisted; no need to call this every time) using the [B4SSingleton setUserName:firstName:gender:email:customerRef:] method:

	[[B4SSingleton sharedInstance] setUserName:@"Bernard" firstName:@"VanCode" gender:kB4SGENDER_MALE email:@"bernard@vancode.com" customerRef:@"90210"];


# Beacon-based notifications

The B4S SDK uses local notifications to establish communication between beacons and the app.

Implement the application:didReceiveLocalNotification: method in your appDelegate. A notification will be sent by the SDK when a notification is fired. You can use the UILocalNotification.userInfo to process the notification yourself. But if you set up some automatic action in the B4S Manager application or using the web app, you must call the [B4SSingleton notificationFeedback:] method. So, the SDK will display a confirmation panel (if any) and process one of the requested predefined actions.


	- (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification
	{
	    [[B4SSingleton sharedInstance] notificationFeedback:notification.userInfo];
	}

After processing a notification, a kB4SNotificationProcessedNotification event is fired by the SDK. The notification type is a B4SActionType that you can get using [[notificationData.userInfo objectForKey:kB4SNotifActionId] intValue]


# Application tagging

You can tag your application with the B4S SDK. You can set two values : The first parameter is the event descriptor and the second the userData asociated to the event. Use the [B4STag event:userData:] and  [B4STag event:userData:]  methods

	[B4STag event:@"menuClose" userData:@"menu_id_42"];
	[B4STag event:@"menuOpen" userDict:@{@"menu_id": @(42), @"item_id": @(12)}];


# B4S Behaviours

This feature allows you to automatically warn the user if Bluetooth, notifications or geolocation are disabled. This setup **must** be done before initializing the B4S Singleton. See the B4SBehaviours class for more details.

	[B4SBehaviours warnForBluetooth:true after:0 count:2 andEvery:2 withTitle:@"Bluetooth" andText:@"Bluetooth is disabled. Do you want to enable it ?"];
	[B4SBehaviours warnForGeolocation:true after:3 count:2 andEvery:2 withTitle:@"Geoloc" andText:@"Geolocation is disabled. Do you want to enable it ?"];
	[B4SBehaviours warnForNotifications:true after:1 count:2 andEvery:2 withTitle:@"Notifications " andText:@"Notifications are disabled. You need to activate them in order to use this application."];

# Custom notifications

You can customize the notification messages and data sent to your application

 *  Implement B4SDelegate in your app delegate

		@interface AppDelegate : UIResponder <UIApplicationDelegate,B4SDelegate>
		
 * In your application:didFinishLaunchingWithOptions: method: set the singleton delegate to your app delegate *after* calling [B4SSingleton setupSharedInstanceWithAppId:]
 
		[B4SSingleton sharedInstance].delegate = self;		
	

 * Implement the [B4SDelegate customizeNotificationText:andData:andUserInfo:completion:] in your app delegate
 
		- (void)customizeNotificationText:(NSString *)aText
		                          andData:(NSString *)aData
		                      andUserInfo:(NSMutableDictionary *)userInfos
		                       completion:(void (^)(NSString *pushText, NSString *pushData, NSMutableDictionary *userInfos))completion {
		    if (completion) {
		        NSLog(@"[customizeNotificationText] set notification text with braces");
		        completion([NSString stringWithFormat:@"[%@]",aText], aData, userInfos);
		    }
		}
	

# Custom alert sound

 * Use [B4SSingleton setNotificationSoundname:] to change the sound played when you app shows a notification to the user. The sound file must be in .caf (Core Audio File) format and imported into your project

		[[B4SSingleton sharedInstance] setNotificationSoundname:@"sound.caf"];

# Push notifications

*To make notifications work you must first follow the instructions of the "Base integration" and "Beacon-based notifications" sections*

