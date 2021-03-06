#include <iostream>
#include <fstream>
#include <string>
#include "wordLadder.H"

using namespace std;

int main(int argc, char *argv[]){
	if ( argc != 4 ) {
		cout << "Usage: wordladder <dictionary_file> <start_word> <end_word>\n";
		return 0;
	}

	wordLadder w1(argv[1]);
	
	w1.outputLadder(argv[2], argv[3]);
	
	return 0;
}


