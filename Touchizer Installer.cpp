#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include "sleep.h"

// For those sweet, sweet progress bars
void showProgressBar(int percentage, const std::string& task) {
    std::cout << "\r" << task << " [";
    int pos = percentage / 2;
    for (int i = 0; i < 50; ++i) {
        if (i < pos) {
            std::cout << "=";
        } else if (i == pos) {
            std::cout << ">";
        } else {
            std::cout << " ";
        }
    }
    std::cout << "] " << percentage << "%";
    std::cout.flush();
}

// Our signature 95% freeze
void freezeAt95(const std::string& task) {
    for (int i = 0; i <= 95; i++) {
        showProgressBar(i, task);
        if (i < 95) {
            // Random delays to look legit
            Sleep(rand() % 100 + 50);
        } else {
            // At 95% - WE FROZE
            std::cout << "\n";
            for (int j = 0; j < 3; j++) {
                std::cout << ".";
                Sleep(1000);
            }
            std::cout << " Just kidding! Still stuck at 95% :3" << std::endl;

            // The infinite loop of disappointment
            while (true) {
                std::cout << "\r█";
                Sleep(500);
                std::cout << "\r▓";
                Sleep(500);
                std::cout << "\r▒";
                Sleep(500);
                std::cout << "\r░";
                Sleep(500);
            }
        }
    }
}

// Create some fake files because why not
void createFakeFiles() {
#ifdef _WIN32
    std::ofstream file("C:\\Program Files\\Touchizer Ultimate\\core.dll");
#elif defined(__APPLE__)
    std::ofstream file("/usr/lib/touchizer_core.dylib");
#elif defined(__linux__)
    std::ofstream file("/usr/lib/touchizer_core.so");
#endif
    file << "This is definitely not a virus :3";
    file.close();

#ifdef _WIN32
    file.open("C:\\Program Files\\Touchizer Ultimate\\Touchizer.exe");
    file << "@echo off\n"
         << "echo Touchizer Ultimate - Doing absolutely nothing !\n"
         << "pause";
    file.close();
#else
    auto fd = open("/usr/bin/touchizer", O_WRONLY | O_CREAT, 100755);
    if (fd == -1) {
        perror("failed to open file");
        return;
    }
    auto str = "#!/bin/bash\n"
               "echo Touchizer Ultimate - Doing absolutely nothing\n"
               "read -p Press enter to continue\n";

    write(fd, str, sizeof(*str));
    close(fd);
#endif
}

int main() {
    // Seed for random delays
    srand(time(NULL));

    std::cout << R"(
    ╔══════════════════════════════════════╗
    ║     TOUCHIZER ULTIMATE INSTALLER     ║
    ║         DOES ABSOLUTELY NOTHING      ║
    ╚══════════════════════════════════════╝

    Warning: This installer will get stuck at 95%
    You have been warned :3

    Press any key to begin your suffering...
    )" << std::endl;

    while (!getchar())
        ;

    std::cout << "\033[H\033[2J";

    std::cout << "Creating"
#ifdef _WIN32
              << "System32"
#elif defined(__APPLE__)
              << "/System"
#elif defined(__linux__)
              << "/"
#endif
              << "backup... (just kidding)" << std::endl;
    Sleep(2000);

    std::cout << "\nStarting installation..." << std::endl;
    Sleep(1000);

    // The fake installation process
    freezeAt95("Installing Touchizer Ultimate");

    return 0; // This will never be reached muahaha
}
