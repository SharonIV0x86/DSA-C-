#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> studentMap;

    // Insert key-value pairs into the map
    studentMap.insert(std::make_pair(1, "Alice"));
    studentMap.insert(std::make_pair(2, "Bob"));
    studentMap.insert(std::make_pair(3, "Charlie"));

    // Access values using keys
    std::cout << "Name of student with ID 2: " << studentMap[2] << std::endl;
    std::cout << "Name of student with ID 1: " << studentMap[1] << std::endl;

    return 0;
}
