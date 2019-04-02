#include <iostream>
#include "version/versionlib.h"

//#include <spdlog/spdlog.h>

int main (int argc, char ** argv){
        std::cout << "Version number "<<version()<<std::endl;
	std::cout << "Hello world"<<std::endl;
//	auto logger = spdlog::stdout_logger_mt("console");
//	logger->info("version {} was started",version());

	return 0;
}
