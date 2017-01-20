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
    B4SInteractionTypePush
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
@property (nonatomic) BOOL isEnabled;
/**
 iBeacon notification data
 */
@property (nonatomic, retain) NSString *pushData;
/**
 iBeacon notification texg
 */
@property (nonatomic, retain) NSString *pushText;

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
 Shops associated to the interaction
 */
@property (readonly) NSMutableDictionary<NSString *, NSString *> *shops;

/*
 * Duration (in seconds) before the interaction can be replayed by the same shop. If duration is 0, the shop can replay the interaction immediately
 */
@property   (nonatomic) NSInteger    placeMuteDuration;

/**
 Returned the B4SInteraction object associated to the given interactionId
 */
+ (B4SInteraction *)getInteractionById:(NSString *)anInteractionId;
/**
 Returns interactions availables
 */
+ (NSArray<B4SInteraction *> *)interactions;

/**
 Returns the number of interactions availables
 */
+ (int)count;

@end
