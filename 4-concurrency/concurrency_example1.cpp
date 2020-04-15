#include <iostream>
#include <thread>

int main() {
    unsigned int nCores = std::thread::hardware_concurrency();
    std::cout << "This machine has " << nCores << " cores available.\n";

    return 0;
}