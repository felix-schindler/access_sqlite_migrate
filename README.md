# Getting started

## Prerequisites (Unix)

You should probably install unixODBC first if you don't already have an ODBC driver manager installed

```bash
brew install unixodbc          # macOS
sudo apt install unixodbc-dev  # Ubuntu
```

## Building

```bash
cmake .
make
```

# IDEs

You can also just use [CLion](https://www.jetbrains.com/clion/) or [Visual Studio](https://visualstudio.microsoft.com/de/downloads/) and do everything from in there.

> - Editors like Fleet need a compilation database. For this, run `cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON .`
> - Visual Studio for Mac does not support developing C++
