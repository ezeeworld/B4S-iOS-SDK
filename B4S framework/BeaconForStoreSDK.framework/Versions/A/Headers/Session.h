//
//  Session.h
//  BeaconForStoreSDK
//
//  Created by Christophe JANOT on 10/06/2014.
//  Copyright (c) 2014 Ezeeworld. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>


@interface Session : NSManagedObject

@property (nonatomic, retain) NSString * sessionId;
@property (nonatomic, retain) NSNumber * sessionType;
@property (nonatomic, retain) NSNumber * endCause;
@property (nonatomic, retain) NSString * globalSessionId;
@property (nonatomic, retain) NSString * country;
@property (nonatomic, retain) NSString * groupId;
@property (nonatomic, retain) NSString * shopId;
@property (nonatomic, retain) NSString * zoneId;
@property (nonatomic, retain) NSString * beaconId;
@property (nonatomic, retain) NSString * ackData;
@property (nonatomic, retain) NSString * interactionId;
@property (nonatomic, retain) NSString * categoryId;
@property (nonatomic, retain) NSNumber * duration;
@property (nonatomic, retain) NSNumber * distance;
@property (nonatomic, retain) NSNumber * appActive;
@property (nonatomic, retain) NSNumber * interactions;
@property (nonatomic, retain) NSDate * date;

@end
