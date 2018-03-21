#include <iostream>
#include <vector>
#include "sorts.h"

int main(int argc, char** argv){
	std::vector<int> nums = {50, 83, 23, 53, 92, 46, 90, 193, 2, 77};
	for(auto num:nums){
		std::cout << num << ", ";
	}
	std::cout << std::endl;

	quicksort(nums);

	for(auto num:nums){
		std::cout << num << ", ";
	}
	std::cout << std::endl;
	
}
