#include <iostream>
#include "version/version_control.h"
int main (int argc, char ** argv){
        std::cout << "Version number "<<TRAVIS_BUILD_NUMBER<<std::endl;
	std::cout << "Hello world"<<std::endl;
	return 0;
}
