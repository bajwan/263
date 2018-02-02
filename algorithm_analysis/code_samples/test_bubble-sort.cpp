#include "bubble_sort.h"
#include <random>
#include <string>

int main(int argc, char** argv){
        int F=std::stoi(argv[1]);
        int nums[] = {10, 9, 7, 8, 6, 5, 3, 4, 1, 2};
        printArray(nums,10);
        bubble_sort(nums,10);
        printArray(nums,10);
        float f[F];
        for(int i=0; i<F; i++){
                f[i] = std::rand();
        }
        std::cout << "Sorting." << std::endl;
        bubble_sort(f,F);
        printArray(f, F);
}
