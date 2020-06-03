#include <iostream>
#include <vector>

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

bool check_equality(std::vector<int> A) {

    int i;
    for (i = 0; i < A.size(); i++) {
        if(A[i] != A[i + 1]) break;
    }
    if (i < A.size() - 1)
        return false;

    return true;
}

int partition(std::vector<int>A, int p, int r) {

    int x = A[r];
    int i = -1;

    if (check_equality(A)) {
        x = A[(p + r)/2];
    }
    
    for(int j = p; j < r - 1; j++) {
        if(A[j] <= x) {
            ++i;
            swap(A[i], A[j]);
        }
    }
    swap(A[++i], A[r]);
    return i;
}

// T(n - 2^i) + O[ (i + 1)n - 2^i - 1 ]