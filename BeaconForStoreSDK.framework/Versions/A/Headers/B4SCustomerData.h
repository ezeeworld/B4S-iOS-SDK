//
//  B4SCustomerData.h
//  BeaconForStoreSDK
//
//  Created by Ezeeworld on 20/05/2014.
//  Copyright (c) 2014 Ezeeworld. All rights reserved.
//

@import Foundation;
#import "B4SCustomerGender.h"

@interface B4SCustomerData : NSObject

/**
 Customer informations as previously set with B4SSingleton method setUserName:firstName:gender:email:customerRef:
 */
@property (nonatomic, retain) NSString *customerRef;
@property (nonatomic, retain) NSString *name;
@property (nonatomic, retain) NSString *firstname;
@property (nonatomic, retain) NSString *email;
@property (nonatomic) B4SCustomerGender gender;

@end