/*
 * Compile with
 * clang++ test.cpp --std=c++11
 */

#include "BinarySearchTree.h"
#include <random>

int main(int argc, char** argv){
	BinarySearchTree<int> bst;
	for(int i=0; i<100; i++){
		// Note we are not seeding the random
		// here.  I wanted the same output
		// each time for learning purposes.

		bst.insert(rand() % 100 + 1);	
	}

	bst.inOrder();
	
}
