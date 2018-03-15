#include <vector>

template <typename Comparable>
void bubble_sort( std::vector<Comparable> & a){
	for(int i=0; i<a.size(); i++){
		for(int j=0; j<a.size(); j++){
			if(a[i] < a[j]){
				std::swap(a[i], a[j]);
			}
		}
	}
}
