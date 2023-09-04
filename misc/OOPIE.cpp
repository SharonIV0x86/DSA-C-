#include <iostream>
#include <string>

class Person {
public:
    std::string name;
    int age;

    void print_info() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    // create two person objects with different values
    Person person1;
    person1.name = "Alice";
    person1.age = 25;

    Person person2;
    person2.name = "Bob";
    person2.age = 30;

    // call print_info() on each object to see their values
    person1.print_info();   // output: "Name: Alice, Age: 25"
    person2.print_info();   // output: "Name: Bob, Age: 30"

    return 0;
}
