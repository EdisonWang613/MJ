cmake_minimum_required(VERSION 3.20)

project(CppCiPractice LANGUAGES CXX)

add_executable(exposure_tests exposure_test.cpp)

target_compile_features(exposure_tests PRIVATE cxx_std_17)

enable_testing()

add_test(
    NAME exposure_limits
    COMMAND exposure_tests
)
