#include <iostream>

int main(int argc, char** argv){
	int a[1000];
	for(int i=0; i<1000; i++){
		a[i] = i;
	}

	std::cout << a[9] << std::endl;
	std::cout << *(a+9) << std::endl;
}
