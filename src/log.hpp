#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <string>

class Log
{
    public:
        static void error(std::string msg);
        static void debug(std::string msg);
        static void debug(int msg);

    private:
        static bool is_verbose;
        static bool is_debug;
};


#endif /* LOG_H */

