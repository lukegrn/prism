#include "conf.h"
#include "consts.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Conf get_conf() {
  Conf c;
  char fp[50];

  strlcpy(fp, getenv("HOME"), sizeof(fp));
  strlcat(fp, "/.config/prism/config", sizeof(fp));

  FILE *f = fopen(fp, "r");

  // Defaults
  if (strcmp(PLATFORM, "osx") == 0) {
    c.sound_path = "/System/Library/Sounds/Blow.aiff";
  } else if (strcmp(PLATFORM, "linux") == 0) {
    c.sound_path = "/usr/share/sounds/freedesktop/stereo/complete.oga";
  }

  if (f == NULL) {
    return c;
  }

  char sound_path[50];

  while (fscanf(f, "sound_path=%s\n", sound_path) != EOF) {
  }

  c.sound_path = sound_path;

  return c;
}
