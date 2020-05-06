#include <iostream>

class DynArray {

    private:
        int *arr;
        int sz, capacity;
        int* resize() {
            capacity *= 2;

            int *pl_arr = new int[capacity];
            for(int i = 0; i < capacity; i++) {
                arr[i] = pl_arr[i];
            }


        }

    public:

        DynArray() {
            sz = 0;
            capacity = 2;

            arr = new int[capacity];

            for(int i = 0; i < capacity; i++) {
                arr[i] = 0;
            }
        }
        int get(int index) {
            // not sorted, so O(n)
            if (index > capacity || index < 0) {
                return -1;
            }
            else if (index > sz) {
                return -1;
            }
            return arr[index];
        }
        void set(int index, int value) {
            if (index > capacity || index < 0) {
                // learn to use exceptions
                std::cout << "This won't work" << std::endl;
                return;
            }
            if (sz == capacity) {
                // there already is an element
                // resize
                // copy
                // then add
            }
            else {
                for(int i = index; i < capacity; i++) {
                    arr[i+1] = arr[i];
                }
                arr[index] = value;
            }
        }
        void push_back(int value) {
            if (sz <= capacity) {
                arr[sz] = value;
                sz++;
            }
            else {
                // resize
                resize();
            }
        }
        void remove(int index) {
            int i = index;
            for(; i < capacity; i++) {
                arr[i] = arr[i+1];
            }

            // do this better
            arr[i] = 0;
        }
        int size() {

        }
};


int main() {
}