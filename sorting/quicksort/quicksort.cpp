#include "partition.cpp"

void quicksort(std::vector<int>A, int p, int r) {
    int q = partition(A, p, r);
    return quicksort(A, p, q - 1);
    return quicksort(A, q + 1, r);
}

int main() {
    std::vector<int> arr;
    arr.push_back(2);
    arr.push_back(8);
    arr.push_back(7);
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(4);

    quicksort(arr, 0, arr.size() - 1);
    for(int x : arr) {
        std::cout << x << std::endl;
    }
}