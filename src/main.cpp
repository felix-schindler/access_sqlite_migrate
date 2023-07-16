#include "main.h"

int main(int argc, char *argv[]) {
    if (1 < argc) {
        handleParams(argc, argv);
    }

    cout << "Hello world" << endl;
    return 0;
}

/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return true When the program should continue
 * @return false When the program should exit
 */
bool handleParams(int argc, char *argv[]) {
    for (int i = 1; i < argc; ++i) {
        // If argument is --help
        if (strcmp(argv[1], "--help") == 0) {
            cout << "Help!" << endl;
            break;
        }

        if (strcmp(argv[1], "--no-log") == 0) {
            cout << "No log!" << endl;
            break;
        }

        std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
    }
}
