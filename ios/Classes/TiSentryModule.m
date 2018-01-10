/**
 * tisentry
 *
 * Created by Rainer
 * Copyright (c) 2018 Your Company. All rights reserved.
 */

#import "TiSentryModule.h"
#import "TiBase.h"
#import "TiHost.h"
#import "TiUtils.h"
#import <Sentry/Sentry.h>

static NSString* sentryDSN = @"";
SentryClient *client;

@implementation TiSentryModule

#pragma mark Internal

// This is generated for your module, please do not change it
- (id)moduleGUID
{
   return @"9097e533-e444-4e24-bcd9-c04586ae17e2";
}

// This is generated for your module, please do not change it
- (NSString *)moduleId
{
    return @"ti.sentry";
}

- (void)errored:(NSNotification *)notification
{
    //   if ([self _hasListeners:@"uncaughtException"]) {
    //       [self fireEvent:@"uncaughtException" withObject:[notification userInfo]];
    //  }
}


#pragma mark Lifecycle

- (void)startup
{
    // This method is called when the module is first loaded
    // You *must* call the superclass
    [super startup];
    DebugLog(@"[DEBUG] %@ loaded", self);
    // importing from tiapp.xml
    // first detecting PRODUCTION/DEVELOPMENT TYPE
    NSError *error = nil;
    client = [[SentryClient alloc] initWithDsn:@"https://<key>:<secret>@sentry.io/<project>" didFailWithError:&error];
    SentryClient.sharedClient = client;
    [SentryClient.sharedClient startCrashHandlerWithError:&error];
    if (nil != error) {
        NSLog(@"%@", error);
    }
}

#pragma Public APIs
- (void)captureMessage:(id)value {
    
}


- (void)captureEvent:(id)value {
}

- (void)startCrashReporting {
    WARN_IF_BACKGROUND_THREAD_OBJ; //NSNotificationCenter is not threadsafe!
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(errored:) name:kTiErrorNotification object:nil];
}

- (void)stopCrashReporting {
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (void)setDSN:(id)value {
    ENSURE_STRING(value);
    sentryDSN = value;
}

@end
