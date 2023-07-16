//
// Created by felix on 16.07.2023.
//

#ifndef ACCESS_SQLITE_MIGRATE_SQLITE_H
#define ACCESS_SQLITE_MIGRATE_SQLITE_H

#pragma once

#include <iostream>
#include <sqlite3.h>

#include "Log.h"

using namespace std;

class SQLite {
private:
    sqlite3 *db;
    char *errorMessage;
public:
    SQLite();
    ~SQLite();
    int execute(const string query);
    string errorMsg();
};

#endif //ACCESS_SQLITE_MIGRATE_SQLITE_H
