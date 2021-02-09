#include <cstdio>
#include <string.h>
#include "print.h"

void next_line()    { printf("\n"); }
void rm_last_line() { printf("\033[A\33[2KT\r"); }

void wprint(const char* text, ccolor color, cstyle style) {
  printf("\033[%d;%dm%s\033[0m", style, color, text);
}

void working_line(const char* line, ccolor linec, cstyle lines, const char* end, ccolor endc, cstyle ends) {
  wprint(line, linec, lines);
  int points = 60 - strlen(line);
  while(points--) {
    wprint(".");
  }
  wprint(end,  endc, ends);
  next_line();
} 

void complete_line(const char* line, ccolor c, cstyle s) {
  working_line(line, c, s, "DONE       ", COLOR_GREEN, STYLE_BOLD);
}

void fail_line(const char* line, ccolor c, cstyle s) {
  working_line(line, c, s, "FAIL       ", COLOR_RED, STYLE_BOLD);
}

void start() { wprint("============================ START! ============================\n", COLOR_WHITE, STYLE_BOLD); }
void fail()  { wprint("============================ FAIL!! ============================\n", COLOR_RED,   STYLE_BOLD); }
void done()  { wprint("=========================== SUCCESS! ===========================\n", COLOR_GREEN, STYLE_BOLD); }

