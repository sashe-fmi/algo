#include<iostream>

void display_array(int* array, int size) {
	std::cout << '[';
	for(int i = 0; i < size - 1; i ++) {
		std::cout << array[i] << ',';
	}
	if(size > 0) {
		std::cout << array[size - 1];
	}
	std::cout << ']';
}

