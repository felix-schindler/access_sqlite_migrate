cmake_minimum_required(VERSION 3.25)
project(access_sqlite_migrate)

set(CMAKE_CXX_STANDARD 23)

# Header files
include_directories(src/include deps/sqlite)            # Include directories where .h files are found

# Add SQLite
add_library(sqlite3 STATIC deps/sqlite/sqlite3.c)       # Define library

# Add own executable
add_executable(access_sqlite_migrate src/main.cpp src/lib/AccessDB.cpp src/lib/SQLite.cpp)
target_link_libraries(access_sqlite_migrate sqlite3)    # Link libraries to my project
