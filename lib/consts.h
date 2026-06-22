#ifndef CONSTS_H_
#define CONSTS_H_

#ifndef PLATFORM
#if defined(__APPLE__)
#define PLATFORM "osx"
#elif defined(__linux__)
#define PLATFORM "linux"
#endif
#endif

#endif
