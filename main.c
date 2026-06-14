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
  time_t now = time(NULL);
  return t.start + t.len - now;
}

void fill_time(int seconds, char *out) {
  int minutes = seconds / 60;
  int rest_seconds = seconds % 60;

  sprintf(out, "%d:%02d", minutes, rest_seconds);
}

int main() {
  initscr();
  noecho();
  cbreak();
  nodelay(stdscr, TRUE);

  Timer t;
  t.start = 1781404426; // This is a hardcoded time from when I was testing,
                        // TODO replace with now
  t.len = 25 * 60;

  keypad(stdscr, TRUE);

  curs_set(0);

  start_color();
  init_pair(1, COLOR_WHITE, COLOR_BLUE);

  attron(COLOR_PAIR(1));

  while (true) {
    clear();
    int x, y;
    getmaxyx(stdscr, y, x);
    char message[25];
    fill_time(remaining(t), message);

    y = y * 0.5;
    x = x * 0.5;
    mvwprintw(stdscr, y, x - strlen(message) / 2, message);

    refresh();
    usleep(0.1 * 1000 * 1000);
  }

  attroff(COLOR_PAIR(1));

  getch();
  endwin();
  return 0;
}
