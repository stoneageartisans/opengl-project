#ifndef LOGGER_H
#define LOGGER_H

#include <string>

using namespace std;

class Logger
{
    public:
        static void log(const char* message);
        static void log(string& message);
};

#endif /* LOGGER_H */
