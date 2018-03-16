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

template <typename Comparable>
void insertion_sort( std::vector<Comparable> & a ){
	for( int p = 1; p < a.size( ); ++p ){
		Comparable tmp = std::move( a[ p ] );
		int j;
		for( j = p; j > 0 && tmp < a[ j - 1 ]; --j ){
			a[ j ] = std::move( a[ j - 1 ] );
		}
		a[ j ] = std::move( tmp );
	}
}
