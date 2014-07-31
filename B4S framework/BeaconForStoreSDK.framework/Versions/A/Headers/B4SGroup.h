//
//  EZBGroup.h
//
//  Created by Christophe JANOT on 19/03/2014.
//  Copyright (c) 2014 Fanny Renauld. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface B4SGroup : NSObject

@property (nonatomic, retain) NSString *groupId;
@property (nonatomic, retain) NSString *name;
@property (nonatomic, retain) NSString *pushText;
@property (nonatomic, retain) NSString *pushData;
@property (nonatomic, retain) NSString *clientRef;

+ (B4SGroup *)addGroup:(B4SGroup *)aGroup;
+ (NSString *)getGroupName:(NSString *)aGroupId;
+ (B4SGroup *)getGroup:(NSString *)aGroupId;
+ (NSArray *)groups;

- (B4SGroup *)initWithName:(NSString *)aName clientRef:(NSString *)aClientRef;
- (Boolean)isValid;
- (void)saveGroup:(B4SGroup *)aGroup
       completion:(void (^)(Boolean success))completion;
- (void)removeGroup:(B4SGroup *)aGroup
         completion:(void (^)(Boolean success))completion;
+ (void)removeGroupById:(NSString *)aGroupId
             completion:(void (^)(Boolean success))completion;

+ (void)clear;
+ (int)count;

@end
