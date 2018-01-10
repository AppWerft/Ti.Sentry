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
#import "AppModule.h"
#import "TiAppPropertiesProxy.h"
#import "TiApp.h"

#import <Sentry/Sentry.h>

extern NSString *const TI_APPLICATION_DEPLOYTYPE;

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

- (void)startup {
   
    [super startup];
    NSString *key = nil;
    NSError *error = nil;
    // detecting PRODUCTION/DEVELOPMENT TYPE
    if ([TI_APPLICATION_DEPLOYTYPE isEqualToString:@"production"]) {
        key = @"SENTRY_DSN_PRODUCTION";
    } else {
        key = @"SENTRY_DSN_DEVELOPMENT";
    }
    // importing properties from tiapp.xml
    sentryDSN = [[TiApp tiAppProperties] objectForKey:key];
    
    client = [[SentryClient alloc] initWithDsn:sentryDSN didFailWithError:&error];
    SentryClient.sharedClient = client;
    [SentryClient.sharedClient startCrashHandlerWithError:&error];
    if (nil != error) {
        NSLog(@"%@", error);
    }
}

#pragma Public APIs
- (void)captureMessage:(id)value {
    if (client != nil) {
        [Sentry logInfo:value];
    }
}


- (void)captureEvent:(id)value {
    if (client != nil) {
        [SentryClient.sharedClient sendEvent:<#(nonnull SentryEvent *)#> withCompletionHandler:<#^(NSError * _Nullable error)completionHandler#>;
         }
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
