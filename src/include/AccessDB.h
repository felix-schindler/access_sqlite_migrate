//
// Created by felix on 16.07.2023.
//

#ifndef ACCESS_SQLITE_MIGRATE_ACCESSDB_H
#define ACCESS_SQLITE_MIGRATE_ACCESSDB_H

#pragma once

#include <sql.h>
#include <sqlext.h>

class AccessDB {
private:
	SQLHANDLE sqlenvhandle;
	SQLHANDLE sqlconnectionhandle;
	SQLHANDLE sqlstatementhandle;
public:
	AccessDB();
	~AccessDB();

	bool connect(const char* connStr);
	void disconnect();
	bool execute(const char* query);
};


#endif //ACCESS_SQLITE_MIGRATE_ACCESSDB_H
