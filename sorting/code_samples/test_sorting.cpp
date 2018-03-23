#include <iostream>
#include <vector>
#include "sorts.h"
#include <string>

int main(int argc, char** argv){
	std::vector<int> nums;
	for(int i=0; i<std::stoi(argv[1]); i++){
		nums.push_back(i);
	}
	quicksort(nums);

}
