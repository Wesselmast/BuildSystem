#include "file.h"
#include "print.h"
#include <dirent.h>
#include <string.h>

#ifndef WEXITSTATUS
# define WEXITSTATUS(stat_val) ((unsigned int) (stat_val) >> 8)
#endif
#ifndef WIFEXITED
# define WIFEXITED(stat_val) (((stat_val) & 255) == 0)
#endif

bool parse_directory(const char* name, std::vector<std::string>& files) {
  DIR* dir = opendir(name);
  if(!dir) {
    wprint("ERROR: ", COLOR_RED, STYLE_BOLD);
    wprint("directory doesn't exist!\n", COLOR_RED);
    return false;
  }
  while(dirent* d = readdir(dir)) {
    char* token1 = strtok(d->d_name, ".");
    char* token2 = strtok(0, ".");
    if(!token2) continue;
    if(!strcmp(token2, "cpp")) {
      files.push_back(std::string(token1));
    }
  }
  closedir(dir);

  if(!files.size()) {
    wprint("ERROR: ", COLOR_RED, STYLE_BOLD);
    wprint("no files in directory!\n", COLOR_RED);
    return false;
  }

  return true;
}

bool execute_cmd(const char* cmd) {
  FILE* pipe = popen(cmd, "r"); 
  return !pclose(pipe);
}

