#include <iostream>
#include <string>
std::size_t hash(std::string &hash);

int main()
{
    std::string str;
    std::cout << "Enter your name: ";
    std::getline(std::cin, str);
    std::cout << hash(str);

    return 0;
}
std::size_t hash(std::string &hash)
{

    std::hash<std::string> hasher;

    // std::string salt = "0x945GHxxJsxper";
    // std::string input = hash + salt;
    std::size_t hashValue = hasher(hash);

    auto key = hashValue % hash.length();
    std::cout << "Key is " << key<< std::endl;
    return hashValue;
}