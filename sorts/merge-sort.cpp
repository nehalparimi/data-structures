#include <iostream>


void merge(int array[], int start, int middle, int end) {
    int l_len, r_len;
    l_len = middle - start;
    r_len = end - middle;

    int l[l_len], r[r_len];

    for(int i = start; i < middle; i++)
        l[i] = array[i];
    
    for(int j = middle+1; j < end; j++)
        r[j] = array[j];

    int m = 0;
    while(m++ < end) {
        if(l[m] <r[m]) {
                
        }
    }
}

int* merge_sort(int array[], int start, int end) {
    int i;
    int middle;

    if(start < end) {
        middle = (start + end)/2;
        merge_sort(array, start, middle);
        merge_sort(array, middle+1, end);
        merge(array, start, middle, end);
    }
}

int main() {

}