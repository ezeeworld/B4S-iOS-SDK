//
//  B4SSingleton.h
//  BeaconForStoreSDK
//
//  Created by Ezeeworld on 23/04/2014.
//  Copyright (c) 2014 Ezeeworld. All rights reserved.
// 

#import <Foundation/Foundation.h>
#import "B4SInteraction.h"
#include    "B4SCustomerGender.h"
#include    "B4SEnums.h"

@class B4SBeacon;

extern NSString *const kB4SNotificationProcessedNotification;

extern NSString *const kB4SBeaconNotificationName;
extern NSString *const kB4SBeaconOutOfRangeNotificationName;
extern NSString *const kB4SConfigurationUpdate;
extern NSString *const kB4SZonesUpdate;
extern NSString *const kB4SUserMoved;
extern NSString *const kB4SInteractionsUpdated;

extern NSString *const kB4SNotifText;
extern NSString *const kB4SNotificationsCount;
extern NSString *const kB4SNotifData;
extern NSString *const kB4SNotifContentId;
extern NSString *const kB4SNotifContentName;
extern NSString *const kB4SNotifBeaconId;
extern NSString *const kB4SNotifBeaconName;
extern NSString *const kB4SNotifNotificationId;
extern NSString *const kB4SNotifDistance;
extern NSString *const kB4SNotifBeaconRef;
extern NSString *const kB4SNotifStoreRef;
extern NSString *const kB4SNotifGroupRef;
extern NSString *const kB4SNotifGroupName;
extern NSString *const kB4SNotifGroupId;
extern NSString *const kB4SNotifShopName;
extern NSString *const kB4SNotifShopId;
extern NSString *const kB4SNotifDate;
extern NSString *const kB4SNotifActionId;
extern NSString *const kB4SNotifPageId;
extern NSString *const kB4SBeaconMajor;
extern NSString *const kB4SBeaconMinor;
extern NSString *const kB4SBeaconUdid;

B4SActionType translateIntToB4SActionTypeValue ( NSInteger anIntValue );

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
 Enable notifications. A categories set can be specified. 
 A default category identifier (B4S) is created for beacons notifications.
*/		  
- (void)notificationsSetup:(NSMutableSet *)categories;
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
 Enable/Disable the SDK bluetooth warning message if Bluetooth is OFF
 */
- (void)setBluetoothWarnStatus:(BOOL)enabled;
/**
Return the full beacons list
*/
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
 If set to true, the interactions list will be set accordingly to the nearest beacon and not the phone location.
*/
- (void)setDemoMode:(BOOL)enabled;
/**
 Force configuration reload (even if already cached) and clear interactions counters.
*/
- (void)demoReset;

- (void)unlockCurrentInteraction;
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
+ (B4SSingleton*) setupSharedInstanceWithAppId:(NSString *)anAppId
                            notificationsSetup:(Boolean)notificationsEnabled;

@end
