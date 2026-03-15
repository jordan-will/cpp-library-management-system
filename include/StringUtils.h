#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string>

namespace utils
{
    inline void trim(std::string& s){

        s.erase(0, s.find_first_not_of(" \t\r\n"));
        s.erase(s.find_last_not_of(" \t\r\n") + 1);
    }  
} 

#endif