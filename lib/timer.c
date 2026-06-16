#include "timer.h"
#include <stdio.h>
#include <time.h>

int remaining(Timer *t) {
  if (t->len == 0) {
    return 0;
  }

  time_t now = time(NULL);
  return t->start + t->len - now;
}

int is_timer_running(Timer *t) { return (t->start + t->len) > time(NULL); }

void strtime(int seconds, char *out) {
  int minutes = seconds / 60;
  int rest_seconds = seconds % 60;

  sprintf(out, "%02d:%02d", minutes, rest_seconds);
}

// If work timer, move to break
// If break timer, move to work
void next(Timer *t) {
  t->start = time(NULL);
  if (t->type == WORK) {
    t->len = 5 * 60;
    t->type = BREAK;
  } else {
    t->len = 25 * 60;
    t->type = WORK;
  }
}

void stop(Timer *t) { t->len = 0; }
