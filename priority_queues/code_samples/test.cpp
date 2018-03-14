#include "BinaryHeap.h"
#include <iostream>

int main(int argc, char** argv){
	BinaryHeap<int> nums(100);;
	for(int i=10; i>0; i--){
		nums.insert(i);
	}

	for(int i=0; i<10; i++){
		std::cout << nums.findMin() << std::endl;
		nums.deleteMin();
	}
}
