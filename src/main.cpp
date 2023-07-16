#include "main.h"
#include <cstring>

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
    // Handle params when
    if (1 < argc) {
        const Action sth = handleParams(argc, argv);

        if (Action::NOTHING != sth) {
            return sth;
        }
    }

    Log::debug("Done running");
    return 0;
}
