//
//  ViewController.m
//  B4S Sample
//
//  Created by Ezeeworld on 30/07/2014.
//  Copyright (c) 2014 ezeeworld. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    [self.navigationController setNavigationBarHidden:YES animated:NO];
    
    NSLog(@">> UUID=%@",[B4SGlobalConfig sharedInstance].udid);
    /*
    NSDictionary    *tags = @{
        @"test": @"TEST",
    };
    [NeerByTag newEvent:@"sdk.testTag" data:tags];*/
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
