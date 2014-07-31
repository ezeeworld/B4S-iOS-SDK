//
//  UserAccount.h
//  BeaconForStoreSDK
//
//  Created by Christophe JANOT on 24/07/2014.
//  Copyright (c) 2014 Ezeeworld. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface B4SUserAccount : NSObject

@property (nonatomic, retain) NSString *name;
@property (nonatomic, retain) NSString *firstName;
@property (nonatomic, retain) NSString *email;
@property (nonatomic, retain) NSString *password;
@property (nonatomic, retain) NSString *company;
@property (nonatomic, retain) NSString *street;
@property (nonatomic, retain) NSString *zipCode;
@property (nonatomic, retain) NSString *city;
@property (nonatomic, retain) NSString *country;
@property (nonatomic, retain) NSString *phone;

@property (nonatomic, retain) NSString *beaconsAccess;
@property (nonatomic, retain) NSString *dashboardAccess;
@property (nonatomic, retain) NSString *interactionsAccess;
@property (nonatomic, retain) NSString *registrationAccess;

@end
