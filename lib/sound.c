#include "sound.h"
#include "conf.h"
#include "consts.h"
#include <stdlib.h>
#include <string.h>

void play() {
  char cmd[100];

  if (strcmp(PLATFORM, "osx") == 0) {
    strlcpy(cmd, "afplay ", sizeof(cmd));
  } else if (strcmp(PLATFORM, "linux") == 0) {
    strlcpy(cmd, "paplay ", sizeof(cmd));
  }

  strlcat(cmd, get_conf().sound_path, sizeof(cmd));
  system(cmd);
}
