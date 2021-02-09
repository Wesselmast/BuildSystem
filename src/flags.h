#pragma once
#include <string>

#define FLAG_USE_OPENGL 1
#define FLAG_USE_GLEW   2
#define FLAG_USE_XLIB   3
#define FLAG_USE_WIN32  4
#define FLAG_OPTIMIZE   5
#define FLAG_DEBUG      6   

int parse_flag(const std::string& flag);
bool parse_flags(int argc, char** argv);
bool is_set(int flag);
