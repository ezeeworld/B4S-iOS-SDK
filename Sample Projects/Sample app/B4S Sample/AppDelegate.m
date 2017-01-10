//
//  AppDelegate.m
//  B4S Sample
//
//  Created by Ezeeworld on 30/07/2014.
//  Copyright (c) 2014 ezeeworld. All rights reserved.
//

#import "AppDelegate.h"
#import <MobileCoreServices/UTCoreTypes.h>
#import <AVFoundation/AVFoundation.h>

@interface AppDelegate ()

@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    if (SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"7.0")) {
        
        // Mandatory configuration: set your App ID and start the SDK
#warning Enter your Ezeeworld app ID here
        [B4SSingleton setupSharedInstanceWithAppId:@"<MY-APP-ID>"];
        [[B4SSingleton sharedInstance] startStandAloneMode];
        
        // Optional setup: warn the user if Bluetooth or notifications are enabled
        [B4SBehaviours warnForBluetooth:true after:2 count:2 andEvery:2 withTitle:@"Bluetooth" andText:@"Bluetooth is disabled. Do you want to enable it ?"];
        [B4SBehaviours warnForNotifications:true after:3 count:2 andEvery:2 withTitle:@"Notifications " andText:@"Notifications are disabled. Do you want to enable them ?"];
        
        // Optional configuration: set user information, configure a delegate, change the default sound
        [[B4SSingleton sharedInstance] setUserProperty:kB4SUserPropertyUserFirstNameKey withString:@"client firstname"];
        [[B4SSingleton sharedInstance] setUserProperty:kB4SUserPropertyUserLastNameKey withString:@"client lastname"];
        [[B4SSingleton sharedInstance] setUserProperty:kB4SUserPropertyUserGenderKey withGender:B4SCustomerGender_FEMALE];
        [[B4SSingleton sharedInstance] setUserProperty:kB4SUserPropertyUsereMailKey withString:@"clientEmail@domain.com"];
        [[B4SSingleton sharedInstance] setUserProperty:kB4SUserPropertyUserCustomerRefNameKey withString:@"yourOwnClientRef"];
        
        [B4SSingleton sharedInstance].delegate = self;
        
        [[B4SSingleton sharedInstance] setNotificationSoundname:@"sound.caf"];
    }
    
    return YES;
}

#pragma mark B4SDelegate

// Optiional: change the notification message on the fly
- (void)customizeNotificationText:(NSString *)aText
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
}


@end