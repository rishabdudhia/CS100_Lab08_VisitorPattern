CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test
	tests/unit_test.cpp
	source/iterator.cpp	
)
ADD_EXECUTABLE(driver
	source/iterator.cpp
	source/main.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE g_test_disable_pthreads=ON)
