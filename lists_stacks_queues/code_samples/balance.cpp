#include <iostream>
#include <stack>
#include <string>
#include <vector>

int main(int argc, char** argv){
	std::string input = argv[1];;
	std::stack<char, std::vector<char> > st;

	for(auto it = input.begin(); it != input.end(); ++it){
		if(*it == '(' || *it == '[' || *it == '{'){
			st.push(*it);
		} else {
			if(*it == ')' && st.top() == ')'){
				st.pop();
			}
		}
	}
}
