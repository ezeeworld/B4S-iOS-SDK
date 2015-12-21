//
//  B4SCategory.h
//  BeaconForStoreSDK
//
//  Created by Ezeeworld on 14/05/2014.
//  Copyright (c) 2014 Ezeeworld. All rights reserved.
//

@import Foundation;

@interface B4SCategory : NSObject

/**
 Category unique internal identifier
 */
@property (nonatomic, retain) NSString *categoryId;
/**
 Category given name
 */
@property (nonatomic, retain) NSString *name;

/**
 Return category name associated to the given categoryId
 */
+ (NSString *)getCategoryName:(NSString *)aCategoryId;
/**
 Return B4SCategory object associated to the given categoryId
 */
+ (B4SCategory *)getCategory:(NSString *)aCategoryId;
/**
 List of categories object downloaded from the backend
 */
+ (NSArray<B4SCategory *> *)categories;

/**
 Number of categories downloaded from the backend
 */
+ (int)count;

@end
