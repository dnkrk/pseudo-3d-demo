#ifndef LOG_H_DEFINED
#define LOG_H_DEFINED

#include <iostream>
#include <string>

class Log {
    public:
        static void error(std::string msg);
        static void debug(std::string msg);
    private:
        static bool is_verbose;
        static bool is_debug;
};


#endif /* LOG_H_DEFINED */

