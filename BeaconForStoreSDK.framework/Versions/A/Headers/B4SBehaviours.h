//
//  B4SBehaviours.h
//  BeaconForStoreSDK
//
//  Created by Ezeeworld on 02/07/2015.
//  Copyright (c) 2015 Ezeeworld. All rights reserved.
//

@import UIKit;

/**
 *  This feature allows you to automatically warn the user if bluetooth, notifications or geolocation are disabled. This setup must be done before initializing the B4S Singleton.
 */
@interface B4SBehaviours : NSObject<UIAlertViewDelegate>


+ (void)warnForBluetooth:(Boolean)aStatus
                   after:(NSInteger)aLaunchCount
                   count:(NSInteger)aMaxCount
                andEvery:(NSInteger)anInterval
               withTitle:(NSString *)aTitle
                 andText:(NSString *)aText;
+ (void)warnForGeolocation:(Boolean)aStatus
                     after:(NSInteger)aLaunchCount
                     count:(NSInteger)aMaxCount
                  andEvery:(NSInteger)anInterval
                 withTitle:(NSString *)aTitle
                   andText:(NSString *)aText;
+ (void)warnForNotifications:(Boolean)aStatus
                       after:(NSInteger)aLaunchCount
                       count:(NSInteger)aMaxCount
                    andEvery:(NSInteger)anInterval
                   withTitle:(NSString *)aTitle
                     andText:(NSString *)aText;
+ (B4SBehaviours *) sharedInstance;

/**
 * Stop everything before SDK shutdown
 */
+ (void)terminate;
@end
