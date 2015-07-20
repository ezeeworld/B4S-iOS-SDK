//
//  B4SInteraction.h
//  BeaconForStoreSDK
//
//  Created by Christophe JANOT on 12/03/2014.
//  Copyright (c) 2014 Christophe JANOT. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "B4SInteraction.h"
#import "B4SShop.h"

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
 Internal interaction unique id
 */
@property (nonatomic, retain) NSString *interactionId;
/**
 Notification activation starting hour [0..23]
 */
@property (nonatomic) int enabledHoursFrom;
/**
 Notification activation ending hour [0..23]
 */
@property (nonatomic) int enabledHoursTo;
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
 True if the notification is tagged as the end of a customer transaction
 */
@property (nonatomic) Boolean isBuyInteraction;
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
@property (nonatomic) Boolean mondayEnabled;
/**
 True if interaction is enabled on tuesdays
 */
@property (nonatomic) Boolean tuesdayEnabled;
/**
 True if interaction is enabled on wednesdays
 */
@property (nonatomic) Boolean wednesdayEnabled;
/**
 True if interaction is enabled on thursdays
 */
@property (nonatomic) Boolean thursdayEnabled;
/**
 True if interaction is enabled on fridays
 */
@property (nonatomic) Boolean fridayEnabled;
/**
 True if interaction is enabled on saturdays
 */
@property (nonatomic) Boolean saturdayEnabled;
/**
 True if interaction is enabled on sundays
 */
@property (nonatomic) Boolean sundayEnabled;
/**
 Shops Categories to the interaction
 */
@property (nonatomic) NSMutableDictionary *categories;
/**
 Groups associated to the interaction
 */
@property (nonatomic) NSMutableDictionary *groups;
/**
 Shops associated to the interaction
 */
@property (nonatomic) NSMutableDictionary *shops;

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
+ (NSArray *)interactions;
/**
 Returns shops near the location set in parameter
 */
+ (NSArray *)shopsList:(CLLocation *)loc;

/**
 Returns the number of interactions availables
 */
+ (int)count;

@end
