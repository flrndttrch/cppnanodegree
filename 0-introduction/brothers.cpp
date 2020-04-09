#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> siblings{"Patrick", "Daniel", "Stefanie"};
    for (std::string const& sibling : siblings) {
        std::cout << sibling << std::endl;
    }
}