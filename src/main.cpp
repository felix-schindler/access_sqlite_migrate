#include <string.h>
#include "Log.h"
#include "SQLite.h"
#include "AccessDB.h"

using namespace std;

// Type declaration
enum Action {
	NOTHING = -1,
	EXIT = 0,
	EXIT_ERROR = 1,
};

/**
 * @brief Handles arguments
 *
 * @param argc Argument count
 * @param argv Arguments
 * @return ACTION
 */
Action handleParams(int argc, char *argv[]) {
	for (int i = 1; i < argc; ++i) {
		// If argument is --help
		if (strcmp(argv[i], "--help") == 0) {
			return Action::EXIT;
		} else if (strcmp(argv[i], "--no-log") == 0) {
			return Action::NOTHING;
		}
	}

	return Action::NOTHING;
}

// -----
// The Main function
// -----
int main(int argc, char *argv[]) {
	// Handle params when there are any
	if (1 < argc) {
		const Action sth = handleParams(argc, argv);

		if (Action::NOTHING != sth) {
			return sth;
		}
	}

	try {
		SQLite *db = new SQLite();
		int rc = db->execute(R"(
CREATE TABLE users (
		id INTEGER PRIMARY KEY AUTOINCREMENT,
		username TEXT NOT NULL UNIQUE,
		password TEXT NOT NULL
);
		)");

		if (SQLITE_OK != rc) {
				cout << db->errorMsg() << endl;
		}

		rc = db->execute("INSERT INTO users (username, password) VALUES ('felix', 'schindler');");

		if (SQLITE_OK != rc) {
				cout << db->errorMsg() << endl;
		}

		rc = db->execute("INSERT INTO users (username, password) VALUES ('florian', 'schindler');");

		if (SQLITE_OK != rc) {
				cout << db->errorMsg() << endl;
		}

		rc = db->execute("SELECT * FROM users;");

		if (SQLITE_OK != rc) {
				cout << db->errorMsg() << endl;
		}

		delete db;
	} catch (const string &error) {
		Log::error(error);
		return 1;
	}

	{
		AccessDB *db = new AccessDB();

		bool rc = db->connect("Driver={Microsoft Access Driver (*.mdb, *.accdb)};DBQ=KVVDat.mdb;");
		if (!rc) {
			Log::error("Could not connect to database");
			return 1;
		}

		delete db;
	}

	Log::info("Done running");
	return 0;
}
