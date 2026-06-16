#include "display.h"
#include <ncurses.h>
#include <string.h>

void setup() {
  initscr();
  noecho();
  cbreak();
  nodelay(stdscr, TRUE);
  keypad(stdscr, TRUE);
  curs_set(0);
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_BLUE);
  attron(COLOR_PAIR(1));
}

void end() {
  attroff(COLOR_PAIR(1));
  endwin();
}

void render(Timer *t) {
  // Clear out previous state for rerender
  erase();

  // Window dimensions
  int x, y;
  getmaxyx(stdscr, y, x);

  // Print in the middle of the frame
  int print_at_y = y * 0.5;
  int print_at_x = x * 0.5;

  // Pretty print timer
  char timer_display[25];
  strtime(remaining(t), timer_display);

  // User instruction
  char user_instruction[40];

  if (!is_timer_running(t)) {
    strlcpy(user_instruction, "Press space to start", sizeof(user_instruction));
    strlcat(user_instruction, t->type == WORK ? " a break" : " working",
            sizeof(user_instruction));
  } else {
    strcpy(user_instruction, "Press space to skip to timer's end");
  }

  int keypress = getch();
  if (keypress != ERR && keypress == 32) {
    if (!is_timer_running(t)) {
      next(t);
    } else {
      stop(t);
    }
  }

  // Display timer
  mvwprintw(stdscr, print_at_y - 1, print_at_x - strlen(user_instruction) / 2,
            user_instruction);
  mvwprintw(stdscr, print_at_y, print_at_x - strlen(timer_display) / 2,
            timer_display);

  refresh();
}
