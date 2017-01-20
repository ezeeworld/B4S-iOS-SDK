//
//  B4SShop.h
//
//  Created by Ezeeworld on 19/03/2014.
//  Copyright (c) 2014 Fanny Renauld. All rights reserved.
//

@import Foundation;

@interface B4SShop : NSObject

@property (nonatomic, retain) NSString *shopId;
@property (nonatomic, retain) NSString *name;
@property (nonatomic, retain) NSString *shopDescription;
@property (nonatomic, retain) NSString *address;
@property (nonatomic, retain) NSString *zipCode;
@property (nonatomic, retain) NSString *city;
@property (nonatomic, retain) NSString *country;

/**
 Customer reference associated to the shop
 */
@property (nonatomic, retain) NSString *clientRef;

/**
 Return B4SShop object associated to the given shopId
 */
+ (B4SShop *)getShopWithId:(NSString *)aShopId;
/**
 Returns the list of shop previously downloaded from the backend
 */

+ (NSArray<B4SShop *> *)shops;

/**
 Return the number of shops.
 */
+ (NSUInteger)count;

/**
 Return the nearest shop.
 */
+ (B4SShop *)nearest;

@end
