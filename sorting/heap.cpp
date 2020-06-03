#include <iostream>
#include <vector>

class Heap {
    std::vector<int> v;
    int heap_size = 0;

public:
    std::vector<int> get_heap();
    void init(std::vector<int>);
    void swap(int&, int&);
    void max_heapify(int);
    void build_max_heap();
    void heap_sort();
};

void Heap::init(std::vector<int> vec) {
    for (int x : vec) {
        v.push_back(x);
        heap_size++;
    }
    build_max_heap();
}

void Heap::swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

std::vector<int> Heap::get_heap() {
    return v;
}

void Heap::max_heapify(int i) {
    if (i > heap_size / 2) return;  // protects against garbage values, some
                                    // of which could be greater than i [down below]
    int left = i << 1;
    int right = (i << 1) + 1;

    int larger = (v[left] >= v[right]) ? left : right;

    if (v[i] >= v[larger]) larger = i;

    if (larger != i) {
        swap(v[i], v[larger]);
        return max_heapify(larger);     // Don't think the return matters in void
    }
}

void Heap::build_max_heap() {
    int n = (heap_size / 2);

    for(; n >= 0; n--) {
        max_heapify(n);
    }
}

void Heap::heap_sort() {
    build_max_heap();

    int n = heap_size - 1;

    for (; n > 1; n--) {
        swap(v[0], v[n]);
        max_heapify(0);
    }
}


int main() {
    Heap heap;
    std::vector<int> v;
    v.push_back(2);

    v.push_back(15);
    v.push_back(92);
    v.push_back(103);
    v.push_back(43);
    v.push_back(12);
    v.push_back(22);
    v.push_back(83);
    v.push_back(36);
    v.push_back(0);
    heap.init(v);
    heap.heap_sort();

    for(int x: heap.get_heap()) {
        std::cout << x << std::endl;
    }
}
