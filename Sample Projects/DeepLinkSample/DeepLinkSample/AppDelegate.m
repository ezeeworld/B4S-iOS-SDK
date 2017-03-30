//
//  AppDelegate.m
//  DeepLinkSample
//
//  Created by Francois Reboursier on 27/06/16.
//  Copyright © 2016 Ezeeworld. All rights reserved.
//

#import "AppDelegate.h"

@import BeaconForStoreSDK;

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // Mandatory configuration: set your App ID and start the SDK
#warning Enter your Ezeeworld app ID in the Info.plist
    [[B4SSingleton sharedInstance] start];
    
    // Optional setup: receive a notification when the SDK handles a notification
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(notificationProcessed:)
                                                 name:kB4SNotificationProcessedNotification
                                               object:nil];

    return YES;
}

- (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification
{
    NSLog(@"[didReceiveLocalNotification] %@ / %@",[notification.userInfo objectForKey:kB4SNotifBeaconId],[notification.userInfo objectForKey:kB4SNotifContentName]);
    NSLog(@"notification : %@",notification.description);
    
    // If you want to use Neerby SDK internal notification processing (UIAlertView, UIWebView, open Url in Safari, ...), you have to call
    // the B4SSingleton::notificationFeedback: method.
    [[B4SSingleton sharedInstance] notificationFeedback:notification.userInfo];
}

- (void)notificationProcessed:(UILocalNotification *)notificationData {
    int actionId = [[notificationData.userInfo objectForKey:kB4SNotifActionId] intValue];
    
    if (actionId == B4SActionType_INAPP) { // The user pressed the action button on the notification
        
        // This variable now contains what was entered in the web interface as the "destination page"
        // Use is as you wish to direct the user to another page within your application
        
        __unused NSString *pageId = [notificationData.userInfo objectForKey:kB4SNotifPageId];
        
    } else if(actionId == B4SActionType_REJECT) {
        // An alertview was set, but the user select the 'Cancel' button. Nothing to do.
    }
}

@end
