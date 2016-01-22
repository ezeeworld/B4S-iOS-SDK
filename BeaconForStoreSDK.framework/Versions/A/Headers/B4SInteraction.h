//
//  B4SInteraction.h
//  BeaconForStoreSDK
//
//  Created by Ezeeworld on 12/03/2014.
//  Copyright (c) 2014 Ezeeworld. All rights reserved.
//

@import Foundation;
@import CoreLocation;

@class  B4SInteraction;
@class  B4SShop;

typedef NS_ENUM(NSInteger, B4SInteractionType)
{
    B4SInteractionTypeUnknown,
    B4SInteractionTypeBeacon,
    B4SInteractionTypeVirtualBeacon,
    B4SInteractionTypePush,
    B4SInteractionTypePassive
};

typedef NS_ENUM(NSInteger, B4SNotificationType)
{
    B4SNotificationTypeSimple,
    B4SNotificationTypeRich,
    B4SNotificationTypeDeeplink,
    B4SNotificationTypePassive
};

@interface B4SInteraction : NSObject

/**
 Interaction given name
 */
@property (nonatomic, retain) NSString *name;
/**
 Interaction description
 */
@property (nonatomic, retain) NSString *interactionDescription;
/**
 ApplicationId the interaction belongs to
 */
@property (nonatomic, retain) NSString *appId;
/**
 Interaction type
 */
@property (nonatomic, readonly) B4SInteractionType type;
/**
 Notification type
 */
@property (nonatomic, readonly) B4SNotificationType notificationType;
/**
 Internal campaign unique id
 */
@property (nonatomic, retain) NSString *campaignId;
/**
 Internal interaction unique id
 */
@property (nonatomic, retain) NSString *interactionId;

/**
 True if the interaction is Enabled
 */
@property (nonatomic) Boolean isEnabled;
/**
 iBeacon notification data
 */
@property (nonatomic, retain) NSString *pushData;
/**
 iBeacon notification texg
 */
@property (nonatomic, retain) NSString *pushText;
/**
 True if the iBeacon pushText and pushData values should be used for the notification
 */
@property (nonatomic) Boolean customPushEnabled;
/**
 Max distance of the notification range
 */
@property (nonatomic) long rangeMax;
/**
 Min distance of the notification range
 */
@property (nonatomic) long rangeMin;
/**
 Distance to reach to exit from the notification range
 */
@property (nonatomic) long rangeOut;
/**
 Maximum number of notification to be sent while the customer stay in the interaction range
 */
@property (nonatomic) int notificationsMaxCount;
/**
 Minimal time to stay in the beacon interaction range before sending a notification
 */
@property (nonatomic) int notificationPresenceDuration;
/**
 Delay between 2 consecutives notifications
 */
@property (nonatomic) long afterScanTimeout;
/**
 True if interaction is enabled on mondays
 */
@property (nonatomic) BOOL mondayEnabled;
/**
 True if interaction is enabled on tuesdays
 */
@property (nonatomic) BOOL tuesdayEnabled;
/**
 True if interaction is enabled on wednesdays
 */
@property (nonatomic) BOOL wednesdayEnabled;
/**
 True if interaction is enabled on thursdays
 */
@property (nonatomic) BOOL thursdayEnabled;
/**
 True if interaction is enabled on fridays
 */
@property (nonatomic) BOOL fridayEnabled;
/**
 True if interaction is enabled on saturdays
 */
@property (nonatomic) BOOL saturdayEnabled;
/**
 True if interaction is enabled on sundays
 */
@property (nonatomic) BOOL sundayEnabled;
/**
 Shops Categories to the interaction
 */
@property (readonly) NSMutableDictionary<NSString *, NSString *> *categories;
/**
 Groups associated to the interaction
 */
@property (readonly) NSMutableDictionary<NSString *, NSString *> *groups;
/**
 Shops associated to the interaction
 */
@property (readonly) NSMutableDictionary<NSString *, NSString *> *shops;

/**
 Returned the B4SInteraction name associated to the given interactionId
 */
+ (NSString *)getInteractionName:(NSString *)anInteractionId;
/**
 Returned the B4SInteraction object associated to the given interactionId
 */
+ (B4SInteraction *)getInteractionById:(NSString *)anInteractionId;
/**
 Returns interactions availables
 */
+ (NSArray<B4SInteraction *> *)interactions;
/**
 Returns shops near the location set in parameter
 */
+ (NSArray<B4SShop *> *)shopsList:(CLLocation *)loc;

/**
 Returns the number of interactions availables
 */
+ (int)count;

@end
