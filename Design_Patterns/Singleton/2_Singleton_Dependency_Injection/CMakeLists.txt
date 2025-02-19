cmake_minimum_required(VERSION 3.14)
project(Singleton_Database_Test_Issue)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Disable pthreads on Windows
if(MSVC)
  set(CMAKE_HAVE_LIBC_PTHREAD OFF CACHE INTERNAL "Test CMAKE_HAVE_LIBC_PTHREAD")
  set(CMAKE_HAVE_PTHREADS_CREATE OFF CACHE INTERNAL "Have library pthreads")
  set(CMAKE_HAVE_PTHREAD_CREATE OFF CACHE INTERNAL "Disable pthread detection")
  set(GTEST_DISABLE_PTHREADS ON CACHE BOOL "Disable pthread support in gtest")
  set(THREADS_PREFER_PTHREADS 0)
  find_package(Threads REQUIRED)
endif()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/a6ce08abf746c0aaa577520d6d1f6ea2abeeb61d.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

# Download and make available googletest
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  RecordFinderTests
  test.cpp
)
target_link_libraries(
  RecordFinderTests
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(
  RecordFinderTests
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
