#include <iostream>
#include <string>

void printMessage(const std::string& message) {
    std::cout << message << std::endl;
}

int main() {
    std::string message = "Hello World !";
    printMessage(message);
    return 0;
}
