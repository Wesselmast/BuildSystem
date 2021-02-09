#pragma once
#include <vector>
#include <string>

bool parse_directory(const char* name, std::vector<std::string>& files);
bool execute_cmd(const char* cmd);
