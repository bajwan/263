#ifndef                 __H_BUBBLE_SORT
#define                 __H_BUBBLE_SORT

#include <iostream>

template <typename T>
void bubble_sort(T* arr, size_t size){
        for(int i=0; i<size; i++){
                for(int j=i+1; j<size; j++){
                        if(arr[i] > arr[j]){
                                T temp = arr[i];
                                arr[i] = arr[j];
                                arr[j] = temp;
                        }
                }
        }
}

template <typename T>
void printArray(T* arr, size_t size){
        for(int i=0; i<size; i++){
                std::cout << arr[i] << "\t";
        }
        std::cout << std::endl;
}

#endif
