//
//  NativeAudioModuleProvider.mm
//  Audio
//
//  Created by Gurwinder Singh on 12/09/26.
//

#import "NativeAudioModuleProvider.h"
#import <ReactCommon/TurboModule.h>

@implementation NativeAudioModuleProvider

RCT_EXPORT_MODULE(NativeAudioModule)

- (std::shared_ptr<facebook::react::TurboModule>)getTurboModule:
    (const facebook::react::ObjCTurboModule::InitParams &)params
{
  return std::make_shared<facebook::react::NativeAudioModuleSpecJSI>(params);
}

- (void)load:(NSString *)name
{
  (void)name;
}

- (void)play {}
- (void)pause {}
- (void)stop {}
- (void)seek:(double)positionMilliseconds
{
  (void)positionMilliseconds;
}

- (NSNumber *)getDuration
{
  return @0;
}

- (NSNumber *)getPosition
{
  return @0;
}

- (NSString *)getState
{
  return @"idle";
}

- (void)playSound:(NSString *)name
{
  [self load:name];
  [self play];
}

@end
