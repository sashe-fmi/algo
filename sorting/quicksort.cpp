#include<iostream>
#include "../helpers.cpp"

void swap(int* left, int* right) {
    int temp = *left;
    *left = *right;
    *right = temp;
}

size_t partition(int* array, int a, int n) {
    int b = (n - a) / 2 - 1;
    int value = array[b];
    swap(&array[b], &array[n - 1]);
    size_t index = a;

    for(int i = a; i < n; i ++) {
        if(array[i] < value) {
            swap(&array[i], &array[index]);
            index = index + 1;
        }
    }
    swap(&array[index], &array[n - 1]);
    return index;
}

void quicksort(int* array, int a, int n) {
    std::cout << a << ' ' << n << "\n";
    if(a < n - 1) {
        int p = partition(array, a, n);
        quicksort(array, a, p);
        quicksort(array, p + 1, n);
    }
}


int main() {
    int w[4] = {4,3,2,0};
    quicksort(w, 0, 4);
    display_array(w, 4);
    std::cout << "\n";
}
