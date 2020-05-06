#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string tag_name = "</tag>";
    std::string tag;
    tag = tag_name.substr(2);
    std::cout << tag_name << " " << tag << std::endl;

}