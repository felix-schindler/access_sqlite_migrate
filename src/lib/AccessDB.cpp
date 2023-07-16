//
// Created by felix on 16.07.2023.
//

#include <iostream>
#include "../include/AccessDB.h"

using namespace std;

AccessDB::AccessDB() {
	cout << "Connecting to Access DB" << endl;
}

AccessDB::~AccessDB() {
	cout << "Disconnecting from Access DB" << endl;
}
