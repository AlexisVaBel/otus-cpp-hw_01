cmake_minimum_required(VERSION 3.2)

if ($ENV{TRAVIS_BUILD_NUMBER})
 project(helloworld VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else ($ENV{TRAVIS_BUILD_NUMBER})
 project(helloworld VERSION 0.0.1)
endif ($ENV{TRAVIS_BUILD_NUMBER})


#project(helloworld VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})



configure_file(version.h.in ${PROJECT_SOURCE_DIR}/version.h)

add_executable(${PROJECT_NAME} main.cpp)

add_library (${PROJECT_NAME}_lib version/versionlib.cpp)


include_directories ("version")


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wpedantic -Wextra")
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lpthread ")


set(SRC_LIST main.cpp)
set(SRC_LIST version/versionlib.cpp)

target_link_libraries (${PROJECT_NAME} ${PROJECT_NAME}_lib)

install (TARGETS helloworld RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT alexisvabel@gmail.com)

set(CPACK_DEBIAN_PACKAGE_SHLIDEPS ON)
include(CPack)


