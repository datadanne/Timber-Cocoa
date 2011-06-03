//
//  TimberTest1AppDelegate.m
//  TimberTest1
//
//  Created by Victor Danell on 2/22/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import "includeCocoa.h"

@implementation TimberTest1AppDelegate

@synthesize window;

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    // Insert code here to initialize your application
}

- (void)dealloc {

    [window release];
    [super dealloc];
}

int main(int argc, char *argv[]) {
    return NSApplicationMain(argc,  (const char **) argv);
}


@end
