#include "lib/display.h"
#include "lib/timer.h"
#include <ncurses.h>
#include <unistd.h>

int main() {
  setup();
  // Init with a break, so that on first start it begins a work timer
  Timer t = {0, 0, BREAK};

  while (true) {
    render(&t);
    usleep(0.1 * 1000 * 1000);
  }

  end();
  return 0;
}
