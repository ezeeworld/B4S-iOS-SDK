//
//  B4SZone.h
//  BeaconForStoreSDK
//
//  Created by Christophe JANOT on 19/05/2014.
//  Copyright (c) 2014 Ezeeworld. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "B4SCategory.h"
#import "B4SShop.h"

static int const    kB4SMinRssForZone = -70;

@interface B4SZone : NSObject

@property (nonatomic, retain) NSString *zoneId;
@property (nonatomic, retain) NSString *name;
@property (nonatomic, weak)   B4SShop *shop;
@property (nonatomic, weak)   B4SCategory *category;

@property (nonatomic, retain) NSMutableArray *beacons;

@property (nonatomic) int x;
@property (nonatomic) int y;
@property (nonatomic) int w;
@property (nonatomic) int h;

- (id)init;
- (NSMutableDictionary *)toNSDictionary;
+ (B4SZone *)addZone:(B4SZone *)aZone;
+ (NSArray *)zones;
+ (void)clear;
+ (int)count;

@end
