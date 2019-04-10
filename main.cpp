#include <iostream>
#include "version/versionlib.h"

int main (int argc, char ** argv){
    std::cout << "build "<<version()<<std::endl;
    std::cout << "Hello, World!"<<std::endl;
    return 0;
}
