#include "hashing_functions.h"
#include <iostream>
#include <string>

int main(int argc, char** argv){
	std::cout << hash("Ira", 10007) << std::endl;
	std::cout << hash2("Ira", 10007) << std::endl;
	std::cout << hash3("Ira", 10007) << std::endl;
}
