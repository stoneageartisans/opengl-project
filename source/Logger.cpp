#include "Logger.h"

#include <iostream>

void Logger::log(const char* message)
{
    std::cout << message << std::endl;
}

void Logger::log(string& message)
{
    std::cout << message << std::endl;
}
