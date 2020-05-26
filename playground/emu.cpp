#include <bits/c++.h>

// We can create a struct to fine-tune our representation of a byte
// That's called bitfields


// We can allot each field the number of bits required by it
struct Byte {
    char unused: 1;
    char switch1: 1;
    char switch2: 1;
    char state: 2;
    char value: 3;
};s

int main() {


    return 0;
}
