//
//  B4SApplication.h
//  BeaconForStoreSDK
//
//  Created by Christophe JANOT on 21/07/2014.
//  Copyright (c) 2014 Ezeeworld. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface B4SApplication : NSObject

@property (nonatomic, retain) NSString *applicationId;
@property (nonatomic, retain) NSString *name;

+ (B4SApplication *)addApplication:(B4SApplication *)anApplication;
+ (NSString *)getApplicationName:(NSString *)anApplicationId;
+ (B4SApplication *)getApplication:(NSString *)anApplicationId;
+ (NSArray *)applications;

- (B4SApplication *)initWithName:(NSString *)aName;
- (Boolean)isValid;
- (void)saveApplication:(B4SApplication *)anApplication
             completion:(void (^)(Boolean success))completion;
- (void)removeApplication:(B4SApplication *)anApplication
               completion:(void (^)(Boolean success))completion;
+ (void)removeApplicationById:(NSString *)anApplicationId
                   completion:(void (^)(Boolean success))completion;

+ (void)clear;
+ (int)count;

@end
