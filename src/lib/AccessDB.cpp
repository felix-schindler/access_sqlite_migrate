//
// Created by felix on 16.07.2023.
//

#include <iostream>
#include "AccessDB.h"
#include "Log.h"

using namespace std;

AccessDB::AccessDB() : sqlenvhandle(NULL), sqlconnectionhandle(NULL), sqlstatementhandle(NULL) {
	Log::debug("Empty DB created");
}

AccessDB::~AccessDB() {
	this->disconnect();
	Log::debug("Disconnected and destroyed DB");
}

bool AccessDB::connect(const char* connStr) {
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlenvhandle))
		return false;

	if (SQL_SUCCESS != SQLSetEnvAttr(sqlenvhandle,SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
		return false;

	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, sqlenvhandle, &sqlconnectionhandle))
		return false;

	switch (SQLDriverConnect(sqlconnectionhandle, NULL,
					(SQLCHAR*)connStr,
					SQL_NTS,
					NULL,
					0,
					NULL,
					SQL_DRIVER_NOPROMPT)) {
		case SQL_SUCCESS:
		case SQL_SUCCESS_WITH_INFO:
			break;
		default:
			return false;
	}

	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlconnectionhandle, &sqlstatementhandle))
		return false;

	return true;
}

void AccessDB::disconnect() {
	if (sqlstatementhandle)
		SQLFreeHandle(SQL_HANDLE_STMT, sqlstatementhandle);
	if (sqlconnectionhandle)
		SQLDisconnect(sqlconnectionhandle);
	if (sqlconnectionhandle)
		SQLFreeHandle(SQL_HANDLE_DBC, sqlconnectionhandle);
	if (sqlenvhandle)
		SQLFreeHandle(SQL_HANDLE_ENV, sqlenvhandle);
}

bool AccessDB::execute(const char* query) {
	if (!sqlstatementhandle)
		return false;

	if (SQL_SUCCESS != SQLExecDirect(sqlstatementhandle, (SQLCHAR*)query, SQL_NTS))
		return false;

	return true;
}
