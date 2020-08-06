cmake_minimum_required(VERSION 3.12.4)

if($ENV{TRAVIS_BUILD_NUMBER})
    set(VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
    set(VERSION 6.6.6)
endif()

project(print_ip VERSION ${VERSION})

find_package(Doxygen COMPONENTS dot REQUIRED)

enable_testing()
add_subdirectory(${CMAKE_SOURCE_DIR}/test)

add_executable(print_ip src/main.cpp)
set_target_properties(print_ip
                        PROPERTIES
                        CXX_STANDARD 17
                        CXX_STANDARD_REQUIRED ON
                      )
target_include_directories(print_ip PRIVATE ${CMAKE_SOURCE_DIR}/src)

configure_file(Doxyfile.in Doxyfile)
add_custom_target(
                 doc
                 ${DOXYGEN_EXECUTABLE} Doxyfile
                 COMMENT "Creating documentation"
                )

install(TARGETS print_ip RUNTIME DESTINATION bin)
set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})

set(CPACK_PACKAGE_CONTACT masteryilerki@yandex.ru)

include(CPack)