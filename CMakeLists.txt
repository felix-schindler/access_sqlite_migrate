cmake_minimum_required(VERSION 3.25)
project(access_sqlite_migrate)

set(CMAKE_CXX_STANDARD 23)

# Add the SQLite library
add_library(SQLite3 INTERFACE)
target_include_directories(SQLite3 INTERFACE ./deps/sqlite3)

# Add own executable
add_executable(access_sqlite_migrate main.cpp main.h lib/access/AccessDB.cpp lib/access/AccessDB.h lib/sqlite/SQLite3.cpp lib/sqlite/SQLite3.h lib/core/Log.h)
target_link_libraries(access_sqlite_migrate PRIVATE SQLite3)
