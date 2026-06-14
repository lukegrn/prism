#include <ncurses.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

typedef struct Timer {
  int start; // When the timer was started, Epoch seconds
  int len;   // How long the timer is
} Timer;

int remaining(Timer t) {
  if (t.start == 0) {
    return 0;
  }

  time_t now = time(NULL);
  return t.start + t.len - now;
}

int is_timer_running(Timer t) { return t.start != 0; }

void fill_time(int seconds, char *out) {
  int minutes = seconds / 60;
  int rest_seconds = seconds % 60;

  sprintf(out, "%02d:%02d", minutes, rest_seconds);
}

int main() {
  initscr();
  noecho();
  cbreak();
  nodelay(stdscr, TRUE);

  Timer t = {0, 0};

  keypad(stdscr, TRUE);

  curs_set(0);

  start_color();
  init_pair(1, COLOR_WHITE, COLOR_BLUE);

  attron(COLOR_PAIR(1));

  while (true) {
    // Clear out previous state for rerender
    erase();

    // Window dimensions
    int x, y;
    getmaxyx(stdscr, y, x);

    // Print in the middle of the frame
    int print_at_y = y * 0.5;
    int print_at_x = x * 0.5;

    // Fill timer
    char message[25];
    fill_time(remaining(t), message);

    // User instruction
    char user_instruction[40];

    if (!is_timer_running(t)) {
      strcpy(user_instruction, "Press space to start");
    } else {
      strcpy(user_instruction, "Press space to skip to timer's end");
    }

    int keypress = getch();
    if (keypress != ERR) { // TODO check keypress
      if (!is_timer_running(t)) {
        t.start = time(NULL);
        t.len = 25 * 60;
      } else {
        t.start = 0;
        t.len = 0;
      }
    }

    mvwprintw(stdscr, print_at_y - 1, print_at_x - strlen(user_instruction) / 2,
              user_instruction);
    mvwprintw(stdscr, print_at_y, print_at_x - strlen(message) / 2, message);

    refresh();
    usleep(0.1 * 1000 * 1000);
  }

  attroff(COLOR_PAIR(1));

  getch();
  endwin();
  return 0;
}
