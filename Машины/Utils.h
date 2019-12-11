#pragma once

#include <sstream>
#include <string>
#include <vector>

class Utils
{
public:
    static std::vector<std::string> split(const std::string& string, char delimiter);
};