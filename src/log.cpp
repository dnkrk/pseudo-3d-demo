#include "log.hpp"

bool Log::is_verbose = false;
bool Log::is_debug = false;

void Log::error(std::string msg)
{
	std::cerr << "Error: " << msg << std::endl;
}

void Log::debug(std::string msg)
{
	std::cout << "Debug: " << msg << std::endl;
}

void Log::debug(int msg)
{
    debug(std::to_string(msg));
}
