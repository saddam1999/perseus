//  Copyright (c) 2021 udevs
//
//  This file is subject to the terms and conditions defined in
//  file 'LICENSE', which is part of this source code package.

#import "Common.h"
#include <objc/runtime.h>
#include <xpc/xpc.h>
#import "PrivateHeaders.h"

#ifdef __cplusplus
extern "C" {
#endif

void sendPerseusQueryWithReply(xpc_object_t message, xpc_handler_t handler);
void sendGeneralPerseusQueryWithReply(xpc_handler_t handler);
void sendInvalidateRSSIPerseusQueryWithReply(xpc_handler_t handler);
void handlePerseusEvent(xpc_object_t event);
id valueForKey(NSString *key);

#ifdef __cplusplus
}
#endif

extern int64_t currentRssi;

typedef NS_ENUM(int64_t, PSQueryType) {
    //0 - Unexpected
    //1 - DetectDisabled
    //2 - Off Wrist
    //3 - On Wrist
    PSQueryTypeWristState = 0,
    //-1 - Unkown
    //0 - Unlocked
    //1 - Locked without AutoUnlock
    //2 - Locked with AutoUnlock
    //3 - Unlocked Without Passcode
    PSQueryTypeLockState = 1,
    PSQueryTypeNearby = 2,
    PSQueryTypeActive = 3,
    PSQueryTypeConnected = 4,
    PSQueryTypeInvalidateRSSI = 5,
    PSQueryTypeRSSI = 6

};
