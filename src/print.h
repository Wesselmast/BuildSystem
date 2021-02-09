#pragma once

enum ccolor {
  COLOR_BLACK   = 30,
  COLOR_RED     = 31,
  COLOR_GREEN 	= 32,
  COLOR_YELLOW  = 33,
  COLOR_BLUE    = 34,
  COLOR_MAGENTA = 35,
  COLOR_CYAN    = 36,
  COLOR_WHITE   = 37
};

enum cstyle {
  STYLE_RESET     = 0,
  STYLE_BOLD      = 1,
  STYLE_UNDERLINE = 4,
};

void wprint(const char* text, ccolor color = COLOR_WHITE, cstyle style = STYLE_RESET);
void next_line();
void rm_last_line();
void working_line(const char* line, ccolor linec, cstyle lines, const char* end, ccolor endc, cstyle ends);

void complete_line(const char* line, ccolor c, cstyle s);
void fail_line(const char* line, ccolor c, cstyle s);

void start();
void fail();
void done();
