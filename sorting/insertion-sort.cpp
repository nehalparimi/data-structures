#include <iostream>
#include <vector>

template <typename T>
std::vector<T> insertion_sort(std::vector<T> &arr) { 
    if (arr.size() == 1) return arr;
    int i, j;

    for(i = 1; i < arr.size(); i++) {
        if(arr[i] < arr[i - 1]) {
            for(j = i; j >= 0; j--) {
                if (arr[j] > arr[j-1]) break;
                T temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;

            }
        } 
    }
    return arr;
}

int main() {
    std::vector<int> arr;
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(5);
    arr.push_back(7);
    arr.push_back(4);
    arr.push_back(1);

    arr = insertion_sort(arr);

    for(int x : arr) {
        std::cout << x << std::endl;
    }
}