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

template <typename Comparable>
void selection_sort( std::vector<Comparable> & a){
	for( int i=0; i<a.size()-1; i++){
		for(int j=i+1; j<a.size(); j++){
			int min_index = i;
			if(a[j] < a[min_index]){
				min_index = j;
			}
			std::swap(a[min_index], a[i]);
		}
	}
}

template <typename Comparable>
void shell_sort( std::vector<Comparable> & a ){
	for( int gap = a.size( ) / 2; gap > 0; gap /= 2 ){
		for( int i = gap; i < a.size( ); ++i ){
			Comparable tmp = std::move( a[ i ] );
			int j=i;
			
			for(;j>=gap&&tmp<a[j-gap];j-=gap){
				a[ j ] = std::move( a[ j - gap ] );
			}

			a[ j ] = std::move( tmp );
		}
	}
}


template <typename Comparable>
void merge( std::vector<Comparable> & a, std::vector<Comparable> & tmpArray, int leftPos, int rightPos, int rightEnd ){
	int leftEnd = rightPos - 1;
	int tmpPos = leftPos;
	int numElements = rightEnd - leftPos + 1;

	while( leftPos <= leftEnd && rightPos <= rightEnd ){
		if( a[ leftPos ] <= a[ rightPos ] ){
			tmpArray[ tmpPos++ ] = std::move( a[ leftPos++ ] );
		} else {
			tmpArray[ tmpPos++ ] = std::move( a[ rightPos++ ] );
		}
	}

	while( leftPos <= leftEnd ){
		tmpArray[tmpPos++] = std::move(a[ leftPos++ ]);
	}

	while( rightPos <= rightEnd ){
		tmpArray[tmpPos++] = std::move(a[ rightPos++ ] );
	}

	for(int i=0;i < numElements; ++i, --rightEnd ){
		a[ rightEnd ] = std::move( tmpArray[ rightEnd ] );
	}
}

template <typename Comparable>
void mergeSort( std::vector<Comparable> & a, std::vector<Comparable> & tmpArray, int left, int right ){
	if(left < right){
		int center = (left + right) / 2;
		mergeSort( a, tmpArray, left, center );
		mergeSort( a, tmpArray, center+1, right );
		merge( a, tmpArray, left, center + 1, right );
	}
}
	
template <typename Comparable>
void mergeSort( std::vector<Comparable> & a ){
	std::vector<Comparable> tmpArray( a.size( ));
	mergeSort( a, tmpArray, 0, a.size( ) - 1);
}


