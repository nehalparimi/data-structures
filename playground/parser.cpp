#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> parser(std::string str, char delim) {
    std::vector<std::string> parsed_container;
    std::string::iterator it = str.begin();
    std::string *nxt = ++it;
    --it;

    std::string placeholder = " ";
    placeholder.clear();

    while(*(nxt++)) {




    }
    return parsed_container;

}

int main() {
    std::string str = "<tag value = \"asshole\" value2 = \"asshole2\">";
    char delim = ' ';

    std::vector<std::string> result = parser(str, delim);

    for(std::string s : result) {
        std::cout << s << std::endl;
    }
}
