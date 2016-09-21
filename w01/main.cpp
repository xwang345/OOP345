#include "process.h"
#include <iostream>

extern const int MAX;
int main(int argc, char *argv[])
{
	if (argc > 1){
		std::cout << "Maximum number of characters stored : " << MAX << std::endl;
		int i = 0;
		for (i = 1; i < argc; i++){
			process(argv[i]);
		}
	}
	else{
		std::cout << "Insufficient number of arguments(min 1)" << std::endl;
	}
}