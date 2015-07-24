//
//  B4SBehaviours.h
//  BeaconForStoreSDK
//
//  Created by Ezeeworld on 02/07/2015.
//  Copyright (c) 2015 Ezeeworld. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  This feature allows you to automatically warn the user if bluetooth, notifications or geolocation are disabled. This setup must be done before initializing the B4S Singleton.
 */
@interface B4SBehaviours : NSObject<UIAlertViewDelegate>

@property (nonatomic) NSInteger foregroundCounts;
@property (nonatomic) Boolean geolocNotified;
@property (nonatomic) Boolean bluetoothNotified;
@property (nonatomic) Boolean notifsNotified;

@property (nonatomic) NSInteger warnBluetoothCount;
@property (nonatomic) Boolean warnForBluetoothDisabled;
@property (nonatomic) NSInteger warnForBluetoothLaunchCount;
@property (nonatomic) NSInteger warnForBluetoothMaxCount;
@property (nonatomic) NSInteger warnForBluetoothIntervalCount;
@property (nonatomic, retain) NSString *warnForBluetoothTitle;
@property (nonatomic, retain) NSString *warnForBluetoothText;

@property (nonatomic) NSInteger warnNotificationsCount;
@property (nonatomic) Boolean warnForNotificationsDisabled;
@property (nonatomic) NSInteger warnForNotificationsLaunchCount;
@property (nonatomic) NSInteger warnForNotificationsMaxCount;
@property (nonatomic) NSInteger warnForNotificationsIntervalCount;
@property (nonatomic, retain) NSString *warnForNotificationsTitle;
@property (nonatomic, retain) NSString *warnForNotificationsText;

@property (nonatomic) NSInteger warnGeolocationCount;
@property (nonatomic) Boolean warnForGeolocationDisabled;
@property (nonatomic) NSInteger warnForGeolocationLaunchCount;
@property (nonatomic) NSInteger warnForGeolocationMaxCount;
@property (nonatomic) NSInteger warnForGeolocationIntervalCount;
@property (nonatomic, retain) NSString *warnForGeolocationTitle;
@property (nonatomic, retain) NSString *warnForGeolocationText;

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

@end
