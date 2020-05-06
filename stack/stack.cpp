#include <iostream>
#include <array>

class Stack {
    
    public:
        int top;
        std::array<int, 100> st;


        void push(int x) {
            st[top++] = x;
        }
        int pop() {
            int last = st[top];
            std::cout << last << "last!!!!!" << "\n\n";
            top--;
            return last;
        }

        Stack() {
            top = 0;
        }

        // Copy constructor

        // takes another stack as a reference
        // that reference stack can (should?) be const
        // because we shouldn't change that value
        Stack(const Stack &C) {
            st = C.st;
            top = 0;
        }

        // friend std::ostream& operator << (std::ostream &output, Stack stack) {
        //     for(int n : stack) {
        //         output << n;
        //     }
        //     return output;
        // }
};

int main() {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    for(int i = 0; i < stack.top; i++) {
        std::cout << stack.st[i] << std::endl;
    }

    std::cout << stack.pop() << std::endl;

    for(int i = 0; i < stack.top; i++) {
        std::cout << stack.st[i] << std::endl;
    }
}