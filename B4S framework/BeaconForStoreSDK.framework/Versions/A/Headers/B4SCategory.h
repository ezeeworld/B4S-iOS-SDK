//
//  B4SCategory.h
//  BeaconForStoreSDK
//
//  Created by Christophe JANOT on 14/05/2014.
//  Copyright (c) 2014 Ezeeworld. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface B4SCategory : NSObject

@property (nonatomic, retain) NSString *categoryId;
@property (nonatomic, retain) NSString *name;

+ (B4SCategory *)addCategory:(B4SCategory *)aCategory;
+ (NSString *)getCategoryName:(NSString *)aCategoryId;
+ (B4SCategory *)getCategory:(NSString *)aCategoryId;
+ (B4SCategory *)defaultCategory;
+ (NSArray *)categories;

- (B4SCategory *)initWithName:(NSString *)aName;
- (Boolean)isValid;
- (void)saveCategory:(B4SCategory *)aCategory
          completion:(void (^)(Boolean success))completion;
- (void)removeCategory:(B4SCategory *)aCategory
            completion:(void (^)(Boolean success))completion;
+ (void)removeCategoryById:(NSString *)aCategoryId
                completion:(void (^)(Boolean success))completion;

+ (void)clear;
+ (int)count;

@end
