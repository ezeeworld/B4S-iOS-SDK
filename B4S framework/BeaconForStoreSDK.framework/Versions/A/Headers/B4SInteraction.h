//
//  EZBContent.h
//  EZBeacon
//
//  Created by Christophe JANOT on 12/03/2014.
//  Copyright (c) 2014 Christophe JANOT. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import "B4SShop.h"

@interface B4SInteraction : NSObject

@property (nonatomic, retain) NSString *name;
@property (nonatomic) long afterScanTimeout;
@property (nonatomic, retain) NSString *appId;
@property (nonatomic, retain) B4SShop *shop;
@property (nonatomic) Boolean autoUnlockEnabled;
@property (nonatomic, retain) NSString *interactionId;
@property (nonatomic) Boolean enabledHoursFrom;
@property (nonatomic) Boolean enabledHoursTo;
@property (nonatomic) Boolean lockOnEnabled;
@property (nonatomic) long proximity;
@property (nonatomic, retain) NSString *pushData;
@property (nonatomic, retain) NSString *pushText;
@property (nonatomic) Boolean customPushEnabled;
@property (nonatomic) Boolean isIncomingInteraction;
@property (nonatomic) Boolean isOutgoingInteraction;
@property (nonatomic) Boolean isBuyInteraction;
@property (nonatomic) long rangeMax;
@property (nonatomic) long rangeMin;
@property (nonatomic) long rangeOut;
@property (nonatomic) int notificationsMaxCount;
@property (nonatomic) int notificationPresenceDuration;
@property (nonatomic) Boolean mondayEnabled;
@property (nonatomic) Boolean tuesdayEnabled;
@property (nonatomic) Boolean wednesdayEnabled;
@property (nonatomic) Boolean thursdayEnabled;
@property (nonatomic) Boolean fridayEnabled;
@property (nonatomic) Boolean saturdayEnabled;
@property (nonatomic) Boolean sundayEnabled;
@property (nonatomic) long type;
@property (nonatomic) NSMutableDictionary *categories;
@property (nonatomic) NSMutableDictionary *groups;
@property (nonatomic) NSMutableDictionary *shops;

- (void)addCategory:(NSString *)category;
- (void)addGroup:(NSString *)group;
- (void)addShop:(NSString *)shop;
- (Boolean)hasCategory:(NSString *)category andGroup:(NSString *)group;
+ (NSString *)getInteractionName:(NSString *)anInteractionId;
+ (B4SInteraction *)getInteractionById:(NSString *)anInteractionId;
+ (B4SInteraction *)addInteraction:(B4SInteraction *)anInteraction;
+ (B4SInteraction *)addInteractionSummary:(B4SInteraction *)anInteraction;
+ (NSArray *)interactions;
+ (NSDictionary *)summary;

- (B4SInteraction *)initWithName:(NSString *)aName;
- (Boolean)isValid;
- (void)saveInteraction:(B4SInteraction *)anInteraction
             completion:(void (^)(Boolean success))completion;
- (void)removeInteraction:(B4SInteraction *)anInteraction
               completion:(void (^)(Boolean success))completion;
+ (void)removeInteractionById:(NSString *)anInteractionId
                   completion:(void (^)(Boolean success))completion;

+ (int)count;
+ (int)fullCount;
+ (void)clearInteractions;
+ (void)clearSummary;
- (void)clear;

@end
