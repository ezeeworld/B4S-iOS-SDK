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
        
        // Optional setup: receive a notification when the SDK handles a notification
        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(notificationProcessed:)
                                                     name:kB4SNotificationProcessedNotification
                                                   object:nil];
        
        
        // Optional setup: warn the user if Bluetooth or notifications are enabled
        [B4SBehaviours warnForBluetooth:true after:2 count:2 andEvery:2 withTitle:@"Bluetooth" andText:@"Bluetooth is disabled. Do you want to enable it ?"];
        [B4SBehaviours warnForNotifications:true after:3 count:2 andEvery:2 withTitle:@"Notifications " andText:@"Notifications are disabled. Do you want to enable them ?"];


        
        
        // Optional configuration: set user information, configure a delegate, change the default sound
        [[B4SSingleton sharedInstance] setUserName:@"ClientName" firstName:@"ClientFirstname" gender:B4SCustomerGender_UNDEFINED email:@"clientEmail@domain.com" customerRef:@"yourOwnClientRef"];
        [B4SSingleton sharedInstance].delegate = self;

        [[B4SSingleton sharedInstance] setNotificationSoundname:@"sound.caf"];
    }
    
    return YES;
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
        NSLog(@"[didReceiveLocalNotification] data=%@",[notificationData.userInfo objectForKey:kB4SNotifInteractionData]);
        NSLog(@"[didReceiveLocalNotification] group clientRef=%@",[notificationData.userInfo objectForKey:kB4SNotifGroupRef]);
        NSLog(@"[didReceiveLocalNotification] store clientRef=%@",[notificationData.userInfo objectForKey:kB4SNotifStoreRef]);
        NSLog(@"[didReceiveLocalNotification] beacon clientRef=%@",[notificationData.userInfo objectForKey:kB4SNotifBeaconRef]);
        NSLog(@"[didReceiveLocalNotification] beacon udid=%@",[notificationData.userInfo objectForKey:kB4SBeaconUdid]);
        NSLog(@"[didReceiveLocalNotification] beacon major=%@",[notificationData.userInfo objectForKey:kB4SBeaconMajor]);
        NSLog(@"[didReceiveLocalNotification] beacon minor=%@",[notificationData.userInfo objectForKey:kB4SBeaconMinor]);
        NSLog(@"[didReceiveLocalNotification] actionId=%d",actionId);
        
        if(actionId == B4SActionType_INAPP) {
            NSString *pageId = [notificationData.userInfo objectForKey:kB4SNotifPageId];
            NSLog(@"[notificationProcessed] inapp pageId : %@",pageId);
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
    if (error) {
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Error!"
                                           message:[error localizedDescription]
                                          delegate:nil
                                 cancelButtonTitle:@"OK"
                                 otherButtonTitles:nil];
        [alert show];
    }
    
}


@end
