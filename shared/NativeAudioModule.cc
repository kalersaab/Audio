
#include "NativeAudioModule.h"

#ifdef __ANDROID__
#include "soundEngine.h"
#endif

namespace facebook::react {

NativeAudioModule::NativeAudioModule(std::shared_ptr<CallInvoker> jsInvoker)
    : NativeAudioModuleCxxSpec(std::move(jsInvoker)) {}

void NativeAudioModule::load(jsi::Runtime &, std::string name) {
#ifdef __ANDROID__
    SoundEngine::load(name);
#else
    (void)name;
#endif
}

void NativeAudioModule::play(jsi::Runtime &) {
#ifdef __ANDROID__
    SoundEngine::play();
#endif
}

void NativeAudioModule::pause(jsi::Runtime &) {
#ifdef __ANDROID__
    SoundEngine::pause();
#endif
}

void NativeAudioModule::stop(jsi::Runtime &) {
#ifdef __ANDROID__
    SoundEngine::stop();
#endif
}

void NativeAudioModule::seek(jsi::Runtime &, double positionMilliseconds) {
#ifdef __ANDROID__
    SoundEngine::seek(positionMilliseconds);
#else
    (void)positionMilliseconds;
#endif
}

double NativeAudioModule::getDuration(jsi::Runtime &) {
#ifdef __ANDROID__
    return SoundEngine::getDuration();
#else
    return 0;
#endif
}

double NativeAudioModule::getPosition(jsi::Runtime &) {
#ifdef __ANDROID__
    return SoundEngine::getPosition();
#else
    return 0;
#endif
}

std::string NativeAudioModule::getState(jsi::Runtime &) {
#ifdef __ANDROID__
    return SoundEngine::getState();
#else
    return "idle";
#endif
}

void NativeAudioModule::playSound(jsi::Runtime &, std::string name) {
#ifdef __ANDROID__
    SoundEngine::play(name);
#else
    (void)name;
#endif
}

} // namespace facebook::react
