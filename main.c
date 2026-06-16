#include "lib/sound.h"
#include "lib/timer.h"
#include "lib/ui.h"
#include <ncurses.h>
#include <unistd.h>

int main() {
  setup();
  // Init with a break, so that on first start it begins a work timer
  Timer t = {0, 0, BREAK};

  while (true) {
    render(&t);
    if (is_timer_running(&t) && should_timer_end(&t)) {
      play();
      stop(&t);
    }
    usleep(0.1 * 1000 * 1000);
  }

  end();
  return 0;
}
