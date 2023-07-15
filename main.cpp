#include "main.h"
#include <sqlite3.h>

int main() {
    sqlite3 *db;

    // Open new in-memory database
    int rc = sqlite3_open(":memory:", &db);

    // Exit with error message, when opening the Database fails
    if (SQLITE_OK != rc) {
        cerr << "Cannot open database " << sqlite3_errmsg(db) << endl;
        return 1;
    }

    // Close the database "connection"
    sqlite3_close(db);
    return 0;
}
