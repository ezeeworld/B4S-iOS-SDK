//
//  B4SShop.h
//
//  Created by Ezeeworld on 19/03/2014.
//  Copyright (c) 2014 Fanny Renauld. All rights reserved.
//

@import Foundation;

@class B4SGroup;

@interface B4SShop : NSObject

@property (nonatomic, retain) NSString *shopId;
@property (nonatomic, retain) NSString *name;
@property (nonatomic, retain) NSString *shopDescription;
@property (nonatomic, retain) NSString *address;
@property (nonatomic, retain) NSString *zipCode;
@property (nonatomic, retain) NSString *city;
@property (nonatomic, retain) NSString *country;

/**
 Notification text associated to the group
 */
@property (nonatomic, retain) NSString *pushText;
/**
 Notification data associated to the group
 */
@property (nonatomic, retain) NSString *pushData;
/**
 Customer reference associated to the group
 */
@property (nonatomic, retain) NSString *clientRef;
/**
 Group the shop belongs to.
 */
@property (nonatomic, retain) B4SGroup *group;

/**
 Return B4SShop object associated to the given shopId
 */
+ (B4SShop *)getShopWithId:(NSString *)aShopId;
/**
 Returns the list of shop previously downloaded from the backend
 */

+ (NSArray<B4SShop *> *)shops;
/**
 Returns the list of shop associated to the given groupId previously downloaded from the backend
 */
+ (NSArray<B4SShop *> *)shopsWithGroupId:(NSString *)groupId;

/**
 Return the number of shops.
 */
+ (NSUInteger)count;

/**
 Return the nearest shop.
 */
+ (B4SShop *)nearest;

@end
