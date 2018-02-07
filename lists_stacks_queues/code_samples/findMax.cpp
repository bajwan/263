#include "Citizen.h"
#include <vector>
#include <string>
#include <iostream>

int main(int argc, char** argv){
	std::vector<Citizen> citizens;
	Citizen one(123456789, "Ira", 40);
	Citizen two(738292934, "Henrietta", 102);
	Citizen three(920948299, "Pete", 16);
	Citizen four(920948299, "Joy", 163);
	citizens.push_back(one);
	citizens.push_back(two);
	citizens.push_back(three);
	citizens.push_back(four);

	Citizen oldest = *(citizens).begin();
	for(auto it = citizens.begin(); it != citizens.end(); ++it){
		if(*it > oldest){
			oldest = *it;
		}
	}

	std::cout << oldest << std::endl;
}
