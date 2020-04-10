//
//  AppDelegate.m
//  B4S Sample
//
//  Created by Ezeeworld on 30/07/2014.
//  Copyright (c) 2014 ezeeworld. All rights reserved.
//

#import "AppDelegate.h"

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    if (SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"7.0")) {
        
        // Mandatory configuration: set your App ID and start the SDK
#warning Enter your Ezeeworld app ID in the Info.plist
        [[B4SSingleton sharedInstance] start];
        
        // Optional configuration: set user information, configure a delegate, change the default sound
        [[B4SSingleton sharedInstance] setUserProperty:kB4SUserPropertyUserFirstNameKey withString:@"client firstname" andLocalOnly:true];
        [[B4SSingleton sharedInstance] setUserProperty:kB4SUserPropertyUserLastNameKey withString:@"client lastname" andLocalOnly:true];
        [[B4SSingleton sharedInstance] setUserProperty:kB4SUserPropertyUserGenderKey withGender:B4SCustomerGender_FEMALE andLocalOnly:true];
        [[B4SSingleton sharedInstance] setUserProperty:kB4SUserPropertyUsereMailKey withString:@"clientEmail@domain.com" andLocalOnly:true];
        [[B4SSingleton sharedInstance] setUserProperty:kB4SUserPropertyUserClientRefKey withString:@"yourOwnClientRef" andLocalOnly:false];
        
        [B4SSingleton sharedInstance].delegate = self;
        
        [[B4SSingleton sharedInstance] setNotificationSoundname:@"sound.caf"];
    }
    
    if ( SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO( @"10.0" ) )
    {
        [UNUserNotificationCenter currentNotificationCenter].delegate = self;
    }
    
    return YES;
}

- (void)userNotificationCenter:(UNUserNotificationCenter* )center willPresentNotification:(UNNotification* )notification withCompletionHandler:(void (^)(UNNotificationPresentationOptions options))completionHandler {
    NSLog( @"Here handle push notification in foreground" );
    //For notification Banner - when app in foreground

    completionHandler(UNNotificationPresentationOptionAlert);

    // Print Notification info
    NSLog(@"Userinfo %@",notification.request.content.userInfo);
}

#pragma mark B4SDelegate

// Optiional: change the notification message on the fly
/*- (void)customizeNotificationText:(NSString *)aText
                          andData:(NSString *)aData
                      andUserInfo:(NSMutableDictionary *)userInfos
                       completion:(void (^)(NSString *pushText, NSString *pushData, NSMutableDictionary *userInfos))completion {
    if(completion) {
        NSLog(@"[customizeNotificationText] userInfos=%@",userInfos);
        NSLog(@"[customizeNotificationText] aText=%@",aText);
        NSLog(@"[customizeNotificationText] set notification text with braces");
        completion([NSString stringWithFormat:@"[%@]",aText], aData, userInfos);
    }
}


- (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification
{
    if (SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"7.0")) {
        NSLog(@"[didReceiveLocalNotification] %@ / %@",[notification.userInfo objectForKey:kB4SNotifBeaconId],[notification.userInfo objectForKey:kB4SNotifContentName]);
        NSLog(@"notification : %@",notification.description);
        
        // If you want to use B4S SDK internal notification processing (UIAlertView, UIWebView, open Url in Safari, ...), you have to call
        // the B4SSingleton::notificationFeedback: method.
        [[B4SSingleton sharedInstance] notificationFeedback:notification.userInfo];
    }
}*/


@end
