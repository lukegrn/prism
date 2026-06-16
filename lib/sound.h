#ifndef PLATFORM
#if defined(__APPLE__)
#define PLATFORM "osx"
#elif defined(__linux__)
#define PLATFORM "linux"
#endif
#endif

#ifndef SOUND_H_
#define SOUND_H_

void play();

#endif
