
#include "Utils.h"

std::vector<std::string> Utils::split(const std::string& string, char delimiter)
{
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream sourse_string(string);
   while (std::getline(sourse_string, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}

