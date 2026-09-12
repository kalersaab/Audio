#pragma once
#include <string>

namespace SoundEngine {

void init();

void load(const std::string &name);

void play();

void pause();

void stop();

void seek(double positionMilliseconds);

double getDuration();

double getPosition();

std::string getState();

void play(const std::string &name);

void release();

} // namespace SoundEngine