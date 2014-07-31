//
//  EZBShop.h
//
//  Created by Christophe JANOT on 19/03/2014.
//  Copyright (c) 2014 Fanny Renauld. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "B4SGroup.h"

@interface B4SShop : NSObject

@property (nonatomic, retain) NSString *shopId;
@property (nonatomic, retain) NSString *name;
@property (nonatomic, retain) NSString *address;
@property (nonatomic, retain) NSString *zipCode;
@property (nonatomic, retain) NSString *city;
@property (nonatomic, retain) NSString *country;

@property (nonatomic, retain) NSString *pushText;
@property (nonatomic, retain) NSString *pushData;
@property (nonatomic, retain) NSString *clientRef;

@property (nonatomic, retain) B4SGroup *group;
@property (nonatomic) int               shopPresenceRange;

@property (nonatomic) float defaultTxPower;
@property (nonatomic) float defaultPathLoss;
@property (nonatomic) float txPowerBatteryCompensation;
@property (nonatomic) float txPowerTemperatureCompensation;
@property (nonatomic) float pathLoss;
@property (nonatomic) float nMapHeading;

+ (B4SShop *)addShop:(B4SShop *)aShop;
+ (NSString *)getShopName:(NSString *)aShopId;
+ (B4SShop *)getShop:(NSString *)aShopId;
+ (NSArray *)shops;
+ (NSArray *)shopsForGroup:(NSString *)groupId;

- (B4SShop *)initWithName:(NSString *)aName group:(B4SGroup *)group clientRef:(NSString *)aClientRef;
- (Boolean)isValid;
- (void)saveShop:(B4SShop *)aShop
      completion:(void (^)(Boolean success))completion;
- (void)removeShop:(B4SShop *)aShop
        completion:(void (^)(Boolean success))completion;
+ (void)removeShopById:(NSString *)aShopId
            completion:(void (^)(Boolean success))completion;

+ (void)clear;
+ (int)count;
+ (int)countForGroup:(NSString *)groupId;
+ (void)setNearestShop:(B4SShop *)shop;
+ (B4SShop *)nearest;

@end
