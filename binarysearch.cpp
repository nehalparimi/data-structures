#include <iostream>

int binary_search(int value, int array[], int start, int end) {

    if (end >= start) {

        int mid = (start + end) / 2;
        if (array[mid] == value) return mid;

        if (value < array[mid]) {
            return binary_search(value, array, 0, mid);
        }
        else {
            return binary_search(value, array, mid+1, end);
        }
    }


}

int main() {
    int array[10] = {1, 2, 3, 4, 5, 6};
    int size = 6;
    int val;

    val = binary_search(1, array, 0, size-1);

    std::cout << val << std::endl;

}   