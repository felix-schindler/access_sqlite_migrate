//
// Created by felix on 16.07.2023.
//

#include "SQLite.h"

int printData(void* data, int argc, char** argv, char** columnNames);

/**
 * Opens new in-memory database
 */
SQLite::SQLite() {
    Log::debug("Opening new in-memory SQLite database");

    // Initialize db object
    this->db = nullptr;
    this->errorMessage = nullptr;

    // Open connection
    int rc = sqlite3_open(":memory:", &db);

    // Exit with error message, when opening the Database fails
    if (SQLITE_OK != rc) {
        const string error = "Cannot open database " + (string)sqlite3_errmsg(db);
        sqlite3_close(db);
        throw error;
    }
}

/**
 * Closes the database connection
 */
SQLite::~SQLite() {
    Log::debug("Closing in-memory db");

    sqlite3_close(db);

    // delete db;
    delete errorMessage;
}

int SQLite::execute(const string query) {
    return sqlite3_exec(db, query.c_str(), printData, 0, &this->errorMessage);
}

string SQLite::errorMsg() {
    if (nullptr == this->errorMessage) {
        return sqlite3_errmsg(db);
    }
    return this->errorMessage;
}

int printData(void* data, int argc, char** argv, char** columnNames) {
    for (int i = 0; i < argc; i++) {
        if (0 != i) {
              cout << " | ";
        }
        cout << columnNames[i];
    }

    cout << endl;

    for (int i = 0; i < argc; i++) {
        if (0 != i) {
            cout << " | ";
        }
        cout << (argv[i] ? argv[i] : "NULL");
    }

    cout << endl;

    return 0;
}
