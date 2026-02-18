#include <ctime>
#include <iostream>
#include "sleep.h"

void uninstallFreezeAt95() {
    std::cout << "\nUninstalling Touchizer Ultimate..." << std::endl;
    Sleep(1000);

    for (int i = 0; i <= 95; i++) {
        std::cout << "\rProgress: " << i << "% ";
        if (i < 95) {
            Sleep(rand() % 100 + 50);
        } else {
            std::cout << "\n";
            for (int j = 0; j < 10; j++) {
                std::cout << "Removing core components";
                for (int k = 0; k < 3; k++) {
                    std::cout << ".";
                    Sleep(500);
                }
                std::cout << "\r                          \r";
            }
            std::cout << "\n";

            // Another infinite loop!
            int counter = 0;
            while (true) {
                std::cout << "\rUninstaller status: STUCK AT 95% FOREVER! ";
                std::cout << "✨ It's been " << counter++ << " seconds ✨";
                Sleep(1000);
            }
        }
    }
}

int main() {
    srand(time(NULL));

    std::cout << R"(
    ╔══════════════════════════════════════╗
    ║   TOUCHIZER ULTIMATE UNINSTALLER     ║
    ║       ALSO STUCK AT 95% LOL          ║
    ╚══════════════════════════════════════╝

    Trying to escape? Too bad!
    )" << std::endl;

    system("pause > nul");
    system("cls");

    uninstallFreezeAt95();

    return 0;
}
