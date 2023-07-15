//
// Created by felix on 16.07.2023.
//

#include "SQLite3.h"

/**
 * Opens new in-memory database
 */
SQLite3::SQLite3() {
    // Initialize db object
    this->db = nullptr;

    // Open connection
    int rc = sqlite3_open(":memory:", &db);

    // Exit with error message, when opening the Database fails
    if (SQLITE_OK != rc) {
        throw "Cannot open database " + (string)sqlite3_errmsg(db);
    }
}

/**
 * Closes the database connection
 */
SQLite3::~SQLite3() {
    sqlite3_close(db);
}
