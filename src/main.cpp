#include "main.h"

int main(int argc, char *argv[]) {
    if (1 < argc) {
        cout << "There are arguments!" << endl;

        for (int i = 1; i < argc; ++i) {
            std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
        }
    }

    cout << "Hello world" << endl;
    return 0;
}
