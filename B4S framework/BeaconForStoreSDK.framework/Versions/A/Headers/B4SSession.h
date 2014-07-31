//
//  B4SSession.h
//  BeaconForStoreSDK
//
//  Created by Christophe JANOT on 20/05/2014.
//  Copyright (c) 2014 Ezeeworld. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "B4SCategory.h"
#import "B4SBeacon.h"

static float const  kB4SGlobalSessionTimeout = 60;
static float const  kB4SZoneSessionTimeout = 20;
static float const  kB4SBeaconSessionTimeout = 20;

enum B4SSessionType {
    kB4SSESSION_GLOBAL,
    kB4SSESSION_ZONE,
    kB4SSESSION_BEACON
};
typedef enum B4SSessionType B4SSessionType;

enum B4SSessionEndCause {
    kB4SSESSION_END_RANGEOUT,
    kB4SSESSION_END_SWAP,
    kB4SSESSION_END_NOBEACONS
};
typedef enum B4SSessionEndCause B4SSessionEndCause;

@interface B4SSession : NSObject

@property (nonatomic) B4SSessionType sessionType;
@property (nonatomic, retain) NSString *sessionId;
@property (nonatomic, retain) NSString *acknowledgeData;
@property (nonatomic, retain) NSDate *sessionStartDate;
@property (nonatomic, retain) NSDate *sessionEndDate;
@property (nonatomic, retain) NSDate *sessionExpirationDate;
@property (nonatomic, retain) B4SCategory *category;
@property (nonatomic, retain) NSString *categoryId;
@property (nonatomic, retain) B4SInteraction *interaction;
@property (nonatomic, retain) NSString *interactionId;
@property (nonatomic, retain) B4SBeacon *beacon;
@property (nonatomic, retain) NSString *beaconId; // Used with offline model
@property (nonatomic, retain) B4SZone *zone;
@property (nonatomic, retain) NSString *zoneId; // Used with offline model
@property (nonatomic, retain) B4SShop *shop;
@property (nonatomic, retain) NSString *shopId; // Used with offline model
@property (nonatomic, retain) NSString *country; // Used with offline model
@property (nonatomic, retain) B4SGroup *group;
@property (nonatomic, retain) NSString *groupId; // Used with offline model
@property (nonatomic, retain) B4SSession *globalSession;
@property (nonatomic, retain) NSString *globalSessionId; // Used with offline model
@property (nonatomic) B4SSessionEndCause endCause;
@property (nonatomic) int interactions;
@property (nonatomic) int duration;
@property (nonatomic) int distance;
@property (nonatomic) Boolean appActive;

+ (void)beaconSense:(B4SBeacon *)beacon interaction:(B4SInteraction *)interaction;
+ (B4SSession *)setGlobalSession:(B4SBeacon *)beacon;
+ (void)endBeaconSession:(B4SSessionEndCause)endCause;
+ (void)endZoneSession:(B4SSessionEndCause)endCause;
+ (void)endGlobalSession:(B4SSessionEndCause)endCause;
+ (void)testGlobalSession;
- (id)init:(B4SSessionType)sessionType;
+ (void)setAcknowledgeData:(NSString *)data;
- (NSString *)getGroupId;
- (NSString *)getZoneId;
- (NSString *)getShopId;
- (NSString *)getShopCountry;
- (NSString *)getBeaconId;
- (NSString *)getCategoryId;
- (NSString *)getInteractionId;
- (NSString *)getAcknowledgeData;
- (int)getSessionDuration;

@end
