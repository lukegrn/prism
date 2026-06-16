#ifndef TIMER_H_
#define TIMER_H_

enum Timer_Type { WORK, BREAK };

typedef struct Timer {
  int start;            // When the timer was started, Epoch seconds
  int len;              // How long the timer is
  enum Timer_Type type; // What kind of timer it is
} Timer;

int remaining(Timer *t);
int is_timer_running(Timer *t);

void strtime(int seconds, char *out);

void next(Timer *t);
void stop(Timer *t);

#endif
