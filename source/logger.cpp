#include <iostream>
#include "logger.h"

void Logger::log(const char* message)
{
    std::cout << message << std::endl;
}

void Logger::log(string& message)
{
    std::cout << message << std::endl;
}
