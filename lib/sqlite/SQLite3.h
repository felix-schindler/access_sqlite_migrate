//
// Created by felix on 16.07.2023.
//

#ifndef ACCESS_SQLITE_MIGRATE_SQLITE3_H
#define ACCESS_SQLITE_MIGRATE_SQLITE3_H

#include <iostream>
#include <sqlite3.h>

using namespace std;

class SQLite3 {
private:
    sqlite3 *db;
public:
    SQLite3();
    ~SQLite3();
};

#endif //ACCESS_SQLITE_MIGRATE_SQLITE3_H
