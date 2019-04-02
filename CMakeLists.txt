cmake_minimum_required(VERSION 3.2)


project(cmake VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

configure_file(version/version.h.in ${PROJECT_SOURCE_DIR}/version/version.h)

add_executable(helloworld_cli main.cpp)

add_library (hellowrold version/versionlib.cpp)


include_directories ("version")


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lpthread ")


set(SRC_LIST main.cpp)
set(SRC_LIST version/versiolib.cpp)

target_link_libraries (helloworld_cli helloworld)

install (TARGETS helloworld_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT alexisvabel@gmail.com)

set(CPACK_DEBIAN_PACKAGE_SHLIDEPS ON)
include(CPack)


