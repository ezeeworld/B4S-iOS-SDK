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

static NSString *const kB4SNotifText = @"text";
static NSString *const kB4SNotifData = @"sInteractionData";
static NSString *const kB4SNotifContentId = @"sInteractionId";
static NSString *const kB4SNotifContentName = @"sInteractionName";
static NSString *const kB4SNotifBeaconId = @"sBeaconId";
static NSString *const kB4SNotifBeaconName = @"sBeaconName";
static NSString *const kB4SNotifNotificationId = @"sNotificationId";
static NSString *const kB4SNotifDistance = @"nDistance";
static NSString *const kB4SNotifBeaconRef = @"sBeaconClientRef";
static NSString *const kB4SNotifStoreRef = @"sStoreClientRef";
static NSString *const kB4SNotifGroupRef = @"sGroupClientRef";
static NSString *const kB4SNotifDate = @"dScanDate";
static NSString *const kB4SNotifActionId = @"nActionId";
static NSString *const kB4SNotifPageId = @"sPageId";
static NSString *const kB4SBeaconMajor = @"sMajor";
static NSString *const kB4SBeaconMinor = @"sMinor";
static NSString *const kB4SBeaconUdid = @"sUdid";

static NSString *const kB4SNotificationProcessedNotification = @"B4SNotificationProcessed";

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

enum B4SActionType {
    kB4SCONFIGUPDT_NONE,
    kB4SCONFIGUPDT_REJECT,
    kB4SCONFIGUPDT_BUSY,
    kB4SCONFIGUPDT_INAPP,
    kB4SCONFIGUPDT_INAPPWEB,
    kB4SCONFIGUPDT_WEB,
    kB4SCONFIGUPDT_IMAGE,
    kB4SCONFIGUPDT_TEXT
    
};
typedef enum B4SActionType B4SActionType;

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

/**
 Set if you do not want more notifications to be sent to the customer.
 */
- (void)setAppNotReadyToAcceptNextInteraction;
/**
 Set if you want to notifications to be sent again to the customer after a previous call to setAppNotReadyToAcceptNextInteraction:
 */
- (void)setAppReadyToAcceptNextInteraction;

- (void)notificationFeedback:(NSDictionary *)userInfo;

+ (B4SSingleton*) sharedInstance;
+ (B4SSingleton*) setupSharedInstanceWithAppId:(NSString *)anAppId;

@end
