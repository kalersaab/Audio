#pragma once

#include <RNAudioSpecJSI.h>

#include <memory>
#include <string>

namespace facebook::react {

class NativeAudioModule : public NativeAudioModuleCxxSpec<NativeAudioModule> {
public:
    explicit NativeAudioModule(std::shared_ptr<CallInvoker> jsInvoker);
    void load(jsi::Runtime &, std::string name);
    void play(jsi::Runtime &);
    void pause(jsi::Runtime &);
    void stop(jsi::Runtime &);
    void seek(jsi::Runtime &, double positionMilliseconds);
    double getDuration(jsi::Runtime &);
    double getPosition(jsi::Runtime &);
    std::string getState(jsi::Runtime &);
    void playSound(jsi::Runtime &, std::string name);
};

} // namespace facebook::react