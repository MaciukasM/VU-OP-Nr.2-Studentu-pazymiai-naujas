cmake_minimum_required(VERSION 3.14)

project(Studentu_pazymiai)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-O2")

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(
  testai
  testai.cpp
)
target_link_libraries(
  testai
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(testai)