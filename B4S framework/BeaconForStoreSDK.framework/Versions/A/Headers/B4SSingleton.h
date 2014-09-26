//
//  B4SSingleton.h
//  BeaconForStoreSDK
//
//  Created by Christophe JANOT on 23/04/2014.
//  Copyright (c) 2014 Ezeeworld. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "B4SInteraction.h"

static NSString *const kB4SBeaconNotificationName = @"B4SBeaconNotification";
static NSString *const kB4SBeaconOutOfRangeNotificationName = @"B4SBeaconOutOfRangeNotification";
static NSString *const kB4SConfigurationUpdate = @"B4SBeaconConfigUpdate";
static NSString *const kB4SZonesUpdate = @"B4SZonesConfigUpdate";

enum B4SBeaconStatus {
    kB4SDETECT_UNDEFINED,
    kB4SDETECT_NO_BEACON,
    kB4SDETECT_MULTIPLE_BEACONS,
    kB4SDETECT_QUERY_BEACON,
    kB4SDETECT_NEW_BEACON,
    kB4SDETECT_REGISTERED,
    kB4SDETECT_REG_ERROR,
    kB4SDETECT_EXISTING,
    kB4SDETECT_SRV_ERROR,
    kB4SDETECT_UNAUTHORIZED
};
typedef enum B4SBeaconStatus B4SBeaconStatus;

enum B4SConfigUpdateCause {
    kB4SCONFIGUPDT_SDKLOOP,
    kB4SCONFIGUPDT_MOVE,
    kB4SCONFIGUPDT_BEACONREG,
    kB4SCONFIGUPDT_IBSDKLOOP,
    kB4SCONFIGUPDT_REGIONIN,
    kB4SCONFIGUPDT_REGIONOUT,
    kB4SCONFIGUPDT_APPSTART

};
typedef enum B4SConfigUpdateCause B4SConfigUpdateCause;

@class B4SSingleton;

@protocol B4SDelegate <NSObject>

@optional
/**
 Delegate method before sent before sending a notification. You can use it to customise notification text and data.
 */
- (void)customizeNotificationText:(NSString *)aText
                          andData:(NSString *)aData
                      andUserInfo:(NSMutableDictionary *)userInfos
                       completion:(void (^)(NSString *pushText, NSString *pushData, NSMutableDictionary *userInfos))completion;
@end

@interface B4SSingleton : NSObject

@property (nonatomic, weak)   id<B4SDelegate> delegate;
@property (nonatomic, retain) NSString *notificationSoundname;

/**
 Force full reload of interactions, groups, shops, beacons
 */
- (void)configRefresh:(B4SConfigUpdateCause)aCause;
/**
 Start iBeacon listening mode
 */
- (void)startStandAloneMode;
/**
 Return the nearest iBeacon
 */
- (B4SBeacon *)queryNearestBeaconStatus;

/**
 Returns last generated notification data.
 */
- (NSDictionary *)getLastNotificationData;

/**
 Called to set the sdk in background mode. Typically used with UIApplication delegate method: applicationDidEnterBackground:
 */
- (void)setBackgroundMode;
/**
 Called to set the sdk in foreground mode. Typically used with UIApplication delegate method: applicationWillEnterForeground:
 */
- (void)setForegroundMode;

- (void)fullBeaconsList:(void (^)(NSArray *beacons))completion;

/**
 Record the current customer information to the backend
 */
- (void)setUserName:(NSString *)aName
          firstName:(NSString *)aFirstname
             gender:(B4SCustomerGender)aGender
              email:(NSString *)anEmail
        customerRef:(NSString *)aRef;
- (void)setAcknowledgeData:(NSString *)data;

+ (B4SSingleton*) sharedInstance;
+ (B4SSingleton*) setupSharedInstanceWithAppId:(NSString *)anAppId;

@end
