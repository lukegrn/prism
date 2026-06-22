#ifndef CONF_H_
#define CONF_H_

typedef struct Conf {
  char *sound_path;
} Conf;

/**
 * get returns the configured sound file, or the default for a given OS in the
 * case that the configured file doesn't exist or is unset
 */
Conf get_conf();

#endif
