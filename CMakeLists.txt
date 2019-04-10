cmake_minimum_required(VERSION 3.2)

if ($ENV{TRAVIS_BUILD_NUMBER})
 project(helloworld VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else ($ENV{TRAVIS_BUILD_NUMBER})
 project(helloworld VERSION 0.0.1)
endif ($ENV{TRAVIS_BUILD_NUMBER})


include_directories ("version")

configure_file(${PROJECT_SOURCE_DIR}/version/version.h.in ${PROJECT_SOURCE_DIR}/version/version.h)

add_executable(${PROJECT_NAME} main.cpp)

add_library (${PROJECT_NAME}_lib ${PROJECT_SOURCE_DIR}/version/versionlib.cpp)


set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)



target_link_libraries (${PROJECT_NAME} ${PROJECT_NAME}_lib)

install (TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT alexisvabel@gmail.com)

set(CPACK_DEBIAN_PACKAGE_SHLIDEPS ON)
include(CPack)


