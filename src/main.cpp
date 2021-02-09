#include "flags.h"
#include "print.h"
#include "file.h"

bool compile_line(const std::string& line) {
  working_line(line.c_str(), COLOR_MAGENTA, STYLE_BOLD, "COMPILING  ", COLOR_YELLOW, STYLE_BOLD);
  rm_last_line();
  std::string cmd = "g++ -c src/" + line + ".cpp -o int/" + line + ".o";
  return execute_cmd(cmd.c_str());
}

bool link_all(const std::string& to_link) {
  std::string link = to_link;
  if(is_set(FLAG_USE_OPENGL)) {
#if defined(__linux__)
    link.append(" -L/usr/include/GL -lGL -lGLU "); 
#elif defined(_WIN32)
    link.append(" -lopengl32 "); 
#endif
  }
  if(is_set(FLAG_USE_GLEW)) {
#if defined(__linux__)
    link.append(" -lGLEW ");
#elif defined(_WIN32)
    link.append(" -I'C:/Program Files/glew/src' -L'C:/Program Files/glew/lib' -lglew32s ");
#endif
  }
  if(is_set(FLAG_USE_XLIB)) {
#if defined(__linux__)
    link.append(" -lX11 " );
#endif
  }
  if(is_set(FLAG_USE_WIN32)) {
#if defined(_WIN32)
    link.append(" -luser32 -lgdi32 ");
#endif
  }
  if(is_set(FLAG_OPTIMIZE)) {
    link.append(" -O2 ");
  }
  if(is_set(FLAG_DEBUG)) {
    link.append(" -D__DEBUG__ -g ");
  }

  return execute_cmd(link.c_str());
}

int main(int argc, char** argv) {
  std::vector<std::string> files;

  if(!parse_directory("./src", files)) return 1;

  std::string name = "app";
  if(argc <= 1) {
    wprint("WARNING: ", COLOR_YELLOW, STYLE_BOLD);
    wprint("no name specified, using default 'app'\n", COLOR_YELLOW);
  }
  else {
    name = argv[1];
  }

  if(!parse_flags(argc, argv)) return 1;

  start();
  std::string to_link = "g++ -o ./bin/" + name;
#if defined(_WIN32)
  to_link.append(".exe");
#endif

  wprint("COMPILING PHASE \n", COLOR_YELLOW, STYLE_BOLD);
  for(std::string& file : files) {
    if(!compile_line(file)) {
      fail_line(file.c_str(), COLOR_MAGENTA, STYLE_BOLD);
      fail();
      return 1;
    }
    complete_line(file.c_str(), COLOR_MAGENTA, STYLE_BOLD);
    to_link.append(" int/" + file + ".o ");
  }
  working_line("LINKING PHASE", COLOR_BLUE, STYLE_BOLD, "LINKING     ", COLOR_BLUE, STYLE_BOLD);
  if(!link_all(to_link.c_str())) {
    fail_line("LINKING PHASE", COLOR_BLUE, STYLE_BOLD);
    fail();
    return 1;
  }
  rm_last_line();
  complete_line("LINKING PHASE", COLOR_BLUE, STYLE_BOLD);
  done();

  return 0;
}
