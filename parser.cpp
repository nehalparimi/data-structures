#include <iostream>
#include <sstream>
#include <vector>
#include <string>

int main() {

    std::map MAP;

    int n, q;
    std::cin >> n >> q;
    std::cin.ignore();

    std::string tag_master;
    std::string tag_input;
    std::string word;

    std::string attribute, value;

    size_t index;

    for(int i = 0; i < n; i++) {
        std::getline(std::cin, tag_input);
        // this splits by word
        while(std::getline(tag_input, word, ' ')) {
            std::string ph;
            if(word[0] == '<') {
                // this is a tag
                if(word[1] == '/') {
                    // this is a closing tag

                }
                else {
                    // this is an opening tag
                    ph = word.substr(1);
                    ph = word.substr(1, word.length() - 1);
                    if(tag_master == "") {
                        tag_master = ph;
                    }
                    else {
                        // tag_master is already populated; skipped control so this must be a nested tag
                        tag_master = tag_master + '.' + ph;
                    }

                }
            }
            else if(word[0] == '"') {
                // this is value
                value = word.substr(1, word.length() - 1);     // remove quotation marks
                MAP[attribute] = value;
            }
            else if(word[0] != '=') {
                // this is attr
                attribute = tag_master + "~" + word;
            }

        }
    }
}