#ifndef		__H_CITIZEN__
#define		__H_CITIZEN__

#include <string>
#include <iostream>

class Citizen {
	public:
		Citizen(int ssn, std::string name,int age){
			this->ssn = ssn;
			this->name = name;
			this->age = age;
		}

		int getAge() const{
			return this->age;
		}

		std::string getName() const{
			return this->name;
		}

		int getSSN() const{
			return this->ssn;
		}

		bool operator< (const Citizen& other) const{
			return this->age < other.age;
		}

		bool operator> (const Citizen& other) const{
			return other < *this;
		}
	private:
		int ssn;
		int age;
		std::string name;
};

std::ostream& operator<<(std::ostream& out, const Citizen& c){
	return out << c.getSSN() << ":" << c.getName() << " is " << c.getAge();
}
#endif
