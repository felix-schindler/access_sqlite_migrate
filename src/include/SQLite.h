//
// Created by felix on 16.07.2023.
//

#ifndef ACCESS_SQLITE_MIGRATE_SQLITE_H
#define ACCESS_SQLITE_MIGRATE_SQLITE_H

#pragma once

#include <iostream>
#include <sqlite3.h>

using namespace std;

class SQLite {
private:
    sqlite3 *db;
public:
    SQLite();
    ~SQLite();
};

#endif //ACCESS_SQLITE_MIGRATE_SQLITE_H
