//
//  AppDelegate.m
//  B4S Sample
//
//  Created by Stéphanie Spenlé on 30/07/2014.
//  Copyright (c) 2014 ezeeworld. All rights reserved.
//

#import "AppDelegate.h"

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    
    //Setup B4S
    B4SSingleton *b4sSingleton = [B4SSingleton setupSharedInstanceWithAppId:@"MY-APP-ID" adminMode:NO];
    [b4sSingleton B4SsetPeriodicBeaconsUpdate:NO];
    [B4SSingleton sharedInstance].delegate = self;
    [[B4SSingleton sharedInstance] startStandAloneMode];
    [b4sSingleton setNotificationSoundname:@"notif.caf"];
    
    return YES;
}


- (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification
{
    NSLog(@"[didReceiveLocalNotification] %@ / %@",[notification.userInfo objectForKey:@"sBeaconId"],[notification.userInfo objectForKey:@"sContentId"]);
    NSLog(@"notification : %@",notification.description);
    NSString *ackStr = [NSString stringWithFormat:@"OPEN#%@:%@",[notification.userInfo objectForKey:@"sBeaconId"],[notification.userInfo objectForKey:@"sContentId"]];
    [[B4SSingleton sharedInstance] setAcknowledgeData:ackStr];
    NSString *cancelButtonTitle = NSLocalizedString(@"OK", @"Title for cancel button in local notification");
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:notification.alertBody message:nil delegate:nil cancelButtonTitle:cancelButtonTitle otherButtonTitles:nil];
    [alert show];
}
							
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
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
