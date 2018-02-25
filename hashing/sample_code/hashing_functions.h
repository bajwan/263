#include <string>

int hash( const std::string & key, int tableSize ){
	int hashVal = 0;

	for(char ch:key){
		hashVal += ch;
	}

	return hashVal % tableSize;
}

int hash2( const std::string & key, int tableSize ){
	return ( key[ 0 ] + 27 * key[ 1 ] + 729 * key[ 2 ] ) % tableSize;
}

unsigned int hash3( const std::string & key, int tableSize ){
	unsigned int hashVal = 0;

	for( char ch:key ){
		hashVal = 37 * hashVal + ch;
	}

	return hashVal % tableSize;
}
