cmake_minimum_required(VERSION 3.14)

project(Tests)

add_subdirectory(${CMAKE_SOURCE_DIR}/test/google_test)

link_libraries(gtest gtest_main)

add_executable(EndianessTest ${CMAKE_SOURCE_DIR}/test/EndianessTest.cpp)
add_executable(OwnTypeTraitsTest ${CMAKE_SOURCE_DIR}/test/OwnTypeTraitsTest.cpp)
add_executable(PrintIPTest ${CMAKE_SOURCE_DIR}/test/PrintIPTest.cpp)

set_target_properties(EndianessTest
                      OwnTypeTraitsTest
                      PrintIPTest
                          PROPERTIES
                          CXX_STANDARD 17
                          CXX_STANDARD_REQUIRED ON
                     )

#target_include_directories(EndianessTest
#                               PRIVATE
#                               ${CMAKE_SOURCE_DIR}/google_test
#                               ${CMAKE_SOURCE_DIR}/src
#                           )
#
#target_include_directories(OwnTypeTraitsTest
#                               PRIVATE
#                               ${CMAKE_SOURCE_DIR}/google_test
#                               ${CMAKE_SOURCE_DIR}/src
#                           )
#
#target_include_directories(PrintIPTest
#                               PRIVATE
#                               ${CMAKE_SOURCE_DIR}/google_test
#                               ${CMAKE_SOURCE_DIR}/src
#                           )

include_directories(${CMAKE_SOURCE_DIR}/google_test ${CMAKE_SOURCE_DIR}/src)
#target_include_directories(EndianessTest
#                           OwnTypeTraitsTest
#                           PrintIPTest
#                               PRIVATE
#                               ${CMAKE_SOURCE_DIR}/google_test
#                               ${CMAKE_SOURCE_DIR}/src
#                           )


#target_link_libraries(EndianessTest
#                          PRIVATE
#                           gtest
#                           gtest_main
#                      )
#
#target_link_libraries(OwnTypeTraitsTest
#                          PRIVATE
#                          gtest
#                          gtest_main
#                      )
#
#target_link_libraries(PrintIPTest
#                          PRIVATE
#                          gtest
#                          gtest_main
#                      )

add_test(NAME EndianessTest COMMAND EndianessTest)
add_test(NAME OwnTypeTraitsTest COMMAND OwnTypeTraitsTest)
add_test(NAME PrintIPTest COMMAND PrintIPTest)
