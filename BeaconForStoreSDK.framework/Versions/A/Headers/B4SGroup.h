//
//  B4SGroup.h
//
//  Created by Ezeeworld on 19/03/2014.
//  Copyright (c) 2014 Fanny Renauld. All rights reserved.
//

@import Foundation;

@interface B4SGroup : NSObject

/**
 Group unique internal identifier
 */
@property (nonatomic, retain) NSString *groupId;
/**
 Group given name
 */
@property (nonatomic, retain) NSString *name;
/**
 Group description
 */
@property (nonatomic, retain) NSString *groupDescription;
/**
 Notification  text associated to the group
 */
@property (nonatomic, retain) NSString *pushText;
/**
 Notification  data associated to the group
 */
@property (nonatomic, retain) NSString *pushData;
/**
 customer reference associated to the group
 */
@property (nonatomic, retain) NSString *clientRef;

/**
 Return group name associated to the given groupId
 */
+ (NSString *)getGroupName:(NSString *)aGroupId;
/**
 Return B4SGroup associated to the given groupId
 */
+ (B4SGroup *)getGroup:(NSString *)aGroupId;
/**
 Returns a list of all groups downloaded from the backend.
 */
+ (NSArray<B4SGroup *> *)groups;

/**
 Number of groups downloaded from the backend
 */
+ (int)count;

@end
