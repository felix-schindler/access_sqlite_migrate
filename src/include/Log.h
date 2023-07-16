//
// Created by felix on 16.07.2023.
//

#ifndef ACCESS_SQLITE_MIGRATE_LOG_H
#define ACCESS_SQLITE_MIGRATE_LOG_H

#pragma once

#include <iostream>
using namespace std;

enum class TerminalColor {
    RESET = 0,
    BLACK = 30,
    RED = 31,
    GREEN = 32,
    YELLOW = 33,
    BLUE = 34,
    MAGENTA = 35,
    CYAN = 36,
    WHITE = 37
};

class Log {
private:
    static string getColorString(TerminalColor color) {
        if (color == TerminalColor::RESET) {
            return "\033[0m";
        }
        string colorString = "\033[" + to_string(static_cast<int>(color)) + "m";
        return colorString;
    }

    static string blue(const string &msg) {
        return Log::getColorString(TerminalColor::BLUE) + msg + Log::getColorString(TerminalColor::RESET);
    }

    static string red(const string &msg) {
        return Log::getColorString(TerminalColor::RED) + msg + Log::getColorString(TerminalColor::RESET);
    }

public:
    static void debug(const string &msg) {
        cout << "[DEBUG] " << msg << endl;
    }

    static void info(const string &msg) {
        cout << Log::blue("[INFO]") << " " << msg << endl;
    }

    static void error(const string &msg) {
        cout << Log::red("[ERROR]") << " " << msg << endl;
    }
};

#endif //ACCESS_SQLITE_MIGRATE_LOG_H
