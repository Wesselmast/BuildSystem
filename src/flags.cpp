#include "flags.h"
#include "print.h"

static int compiler_flags;

int parse_flag(const std::string& flag) {
  if(flag == "USE_OPENGL") return FLAG_USE_OPENGL;
  if(flag == "USE_GLEW")   return FLAG_USE_GLEW;
  if(flag == "USE_XLIB")   return FLAG_USE_XLIB;  
  if(flag == "USE_WIN32")  return FLAG_USE_WIN32;
  if(flag == "OPTIMIZE")   return FLAG_OPTIMIZE;   
  if(flag == "DEBUG")      return FLAG_DEBUG;  

  wprint("ERROR: ", COLOR_RED, STYLE_BOLD);
  wprint("flag '",  COLOR_RED);
  wprint(flag.c_str(), COLOR_RED);
  wprint("' doesn't exist or hasn't been implemented\n", COLOR_RED);

  return 0;
} 

bool parse_flags(int argc, char** argv) {
  compiler_flags = 0;
  for(int i = 2; i < argc; ++i) {
    std::string str(argv[i]);
    int ret = parse_flag(str);
    if(!ret) return false;
    compiler_flags |= 1UL << ret; 
  }
  return true;
}

bool is_set(int flag) {
  return compiler_flags & 1UL << flag;
}
