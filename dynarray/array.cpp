#include <iostream>

class DynArray {
    private:
        int *arr;
        int sz, capacity;
        int& resize() {
            capacity *= 2;

            int *pl_arr = new int[capacity];
            for(int i = 0; i < capacity; i++) {
                if (capacity <= sz) {
                    // until the point at which the old array had values
                    arr[i] = pl_arr[i];
                }
                else {
                    // clear the array of garbage values
                    pl_arr[i] = 0;
                }  
            }
            // we can delete the memory 'held' by arr, and then *make it point* to the new arr we created
            // that way, the class understands arr to be the new array, AND we don't use pl_arr (our mehtods would break)
            // if that was permanent
            delete [] arr;
            arr = pl_arr;
            return *arr;
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
        ~DynArray() {
            delete [] arr;
        }
            int get(int index) {
            // not sorted, so O(n)
            if (index > capacity || index < 0) {
                std::cout << "Segmentation Fault 1.1" << std::endl;
                return -1;
            }
            return arr[index];
        }

        // void set(int index, int value) {
            
        // }

        void push_back(int value) {
            if (sz == capacity) {
                arr = &resize();
            }
           arr[sz] = value;
           sz++;
        }
        void remove(int index) {

            if (index > capacity) {
                std::cout << "Segmentation Fault 1.1; please check input" << std::endl; 
                return;
            }
            if (index == capacity) {
                // pop the element
                arr[index] = 0;
                return;
            }
            int i = index;
            for(; i < capacity-1; i++) {
                arr[i] = arr[i+1];
            }
            // do this better; last index
            arr[i] = 0;
        }
        int size() {
            return sz;
        }

        int& operator[](int index) {
            // return reference to index
        }
};


int main() {

}