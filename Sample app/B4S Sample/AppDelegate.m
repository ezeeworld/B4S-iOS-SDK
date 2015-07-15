//
//  AppDelegate.m
//  B4S Sample
//
//  Created by Stéphanie Spenlé on 30/07/2014.
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
        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(notificationProcessed:)
                                                     name:kB4SNotificationProcessedNotification
                                                   object:nil];
        //Setup B4S
        [B4SBehaviours warnForBluetooth:false after:2 count:2 andEvery:2 withTitle:@"Bluetooth" andText:@"Bluetooth is disabled. Do you want to enabled it ?"];
        [B4SBehaviours warnForNotifications:false after:3 count:2 andEvery:2 withTitle:@"Notifications " andText:@"Notifications are disabled. Do you want to enabled them ?"];

        B4SSingleton *b4sSingleton = [B4SSingleton setupSharedInstanceWithAppId:@"MY-APP-ID"]; // MY-APP-ID have to be replaced with one of your own APPID
        [B4SSingleton sharedInstance].delegate = self;
        [b4sSingleton setUserName:@"ClientName" firstName:@"ClientFirstname" gender:kB4SGENDER_UNDEFINED email:@"clientEmail@domain.com" customerRef:@"yourOwnClientRef"];
        
        [[B4SSingleton sharedInstance] startStandAloneMode];
        [b4sSingleton setNotificationSoundname:@"sound.caf"];
    }
    
    return YES;
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

/**
 * After notification processing, the B4S SDK send a LocalNotification (kB4SNotificationProcessedNotification).
 */
- (void)notificationProcessed:(UILocalNotification *)notificationData {
    if (SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"7.0")) {
        int actionId = [[notificationData.userInfo objectForKey:kB4SNotifActionId] intValue];
        
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
        
        if(actionId == B4SActionType_INAPP) {
            NSString *pageId = [notificationData.userInfo objectForKey:kB4SNotifPageId];
            NSLog(@"[didReceiveLocalNotification] inapp pageId : %@",pageId);
            // Open the application UIView associated to the pageId value
            if([pageId isEqualToString:@"photoTest"]) { // 'photo' pageId is already supported inside the SDK
                UIImagePickerController *picker = [[UIImagePickerController alloc] init];
                picker.delegate = self;
                picker.allowsEditing = YES;
                picker.sourceType = UIImagePickerControllerSourceTypeCamera;
                picker.showsCameraControls = YES;
                
                UINavigationController *navigationController = (UINavigationController *)self.window.rootViewController;
                [navigationController presentViewController:picker animated:YES completion:NULL];
                [[B4SSingleton sharedInstance] setAppNotReadyToAcceptNextInteraction];
            } else if([pageId isEqualToString:@"twitterTest"]) { // 'twitter' pageId is already supported inside the SDK
                dispatch_async(dispatch_get_main_queue(), ^{ // Accelerate the switch to the application.
                    if ([[UIApplication sharedApplication] canOpenURL:[NSURL URLWithString:@"twitter://"]]) {
                        [[UIApplication sharedApplication] openURL:[NSURL URLWithString:@"twitter://post?message="]];
                    }
                });
            } else if([pageId isEqualToString:@"calendarTest"]) { // 'calendar' pageId is already supported inside the SDK
                dispatch_async(dispatch_get_main_queue(), ^{ // Accelerate the switch to the application.
                    if ([[UIApplication sharedApplication] canOpenURL:[NSURL URLWithString:@"calshow://"]]) {
                        [[UIApplication sharedApplication] openURL:[NSURL URLWithString:@"calshow://"]];
                    }
                });
            }
        } else if(actionId == B4SActionType_REJECT) {
            // An alertview was set, but the user select the 'Cancel' button. Nothing to do.
        }
    }
}

#pragma mark UIImagePickerControllerDelegates
- (void) imagePickerController:(UIImagePickerController *)picker
 didFinishPickingMediaWithInfo:(NSDictionary *)info {
    NSLog(@"Media Info: %@", info);
    NSString *mediaType = [info valueForKey:UIImagePickerControllerMediaType];
    
    if([mediaType isEqualToString:(NSString*)kUTTypeImage]) {
        UIImage *photoTaken = [info objectForKey:@"UIImagePickerControllerOriginalImage"];
        
        //Save Photo to library only if it wasnt already saved i.e. its just been taken
        if (picker.sourceType == UIImagePickerControllerSourceTypeCamera) {
            UIImageWriteToSavedPhotosAlbum(photoTaken, self, @selector(image:didFinishSavingWithError:contextInfo:), nil);
        }
        
    }
    [picker dismissViewControllerAnimated:NO completion:nil];
    [[B4SSingleton sharedInstance] setAppReadyToAcceptNextInteraction];
}

- (void)imagePickerControllerDidCancel:(UIImagePickerController *)picker {
    [picker dismissViewControllerAnimated:NO completion:nil];
    [[B4SSingleton sharedInstance] setAppReadyToAcceptNextInteraction];
}

#pragma mark --

- (void)image:(UIImage *)image didFinishSavingWithError:(NSError *)error contextInfo:(void *)contextInfo {
    UIAlertView *alert;
    NSLog(@"Image:%@", image);
    if (error) {
        alert = [[UIAlertView alloc] initWithTitle:@"Error!"
                                           message:[error localizedDescription]
                                          delegate:nil
                                 cancelButtonTitle:@"OK"
                                 otherButtonTitles:nil];
        [alert show];
    }
    
}

#pragma mark B4SDelegate
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
#pragma mark --

#pragma mark UIApplicationDelegate
- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
    
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
    [[B4SSingleton sharedInstance] configRefresh:B4SConfigUpdateCause_APPSTART];
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}
#pragma mark --

@end
