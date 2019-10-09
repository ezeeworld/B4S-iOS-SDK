//
//  AppDelegate.h
//  B4S Sample
//
//  Created by Ezeeworld on 30/07/2014.
//  Copyright (c) 2014 ezeeworld. All rights reserved.
//


@import UIKit;

@import BeaconForStoreSDK;

#import <UserNotifications/UserNotifications.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate, UNUserNotificationCenterDelegate, B4SDelegate>

@property (strong, nonatomic) UIWindow *window;

@end
