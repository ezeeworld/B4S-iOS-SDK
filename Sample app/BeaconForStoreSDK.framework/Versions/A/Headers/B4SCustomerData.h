//
//  B4SCustomerData.h
//  BeaconForStoreSDK
//
//  Created by Christophe JANOT on 20/05/2014.
//  Copyright (c) 2014 Ezeeworld. All rights reserved.
//

#import <Foundation/Foundation.h>

enum B4SCustomerGender {
    kB4SGENDER_UNDEFINED,
    kB4SGENDER_FEMALE,
    kB4SGENDER_MALE
};
typedef enum B4SCustomerGender B4SCustomerGender;

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
