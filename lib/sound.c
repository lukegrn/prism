#include "sound.h"
#include <stdlib.h>
#include <string.h>

void play() {
  if (strcmp(PLATFORM, "osx") == 0) {
    system("afplay /System/Library/Sounds/Blow.aiff");
  } else if (strcmp(PLATFORM, "linux")) {
    system("paplay /usr/share/sounds/freedesktop/stereo/complete/oga");
  }
}
