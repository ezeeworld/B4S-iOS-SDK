//
//  B4SMotionDetector.h
//  BeaconForStoreSDK
//
//  Created by Christophe JANOT on 27/05/2014.
//  Copyright (c) 2014 Ezeeworld. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMotion/CoreMotion.h>

enum B4SMovement {
    kB4SMOVE_NO,
    kB4SMOVE_SLOW,
    kB4SMOVE_FAST
};
typedef enum B4SMovement B4SMovement;

@interface B4SMotionDetector : NSObject

@property (nonatomic, retain) CMMotionManager *motionManager;
@property (nonatomic) B4SMovement moving;

- (id)initWithThreshold:(float)accelerationThreshold1 and:(float)accelerationThreshold2;
- (B4SMovement)movement;

@end
