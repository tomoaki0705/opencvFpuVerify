# CMake minimun version
cmake_minimum_required(VERSION 2.8)

# executable name
set(TARGET_NAME verifyFpu)

# solution name
project(${TARGET_NAME})

# executable
add_executable(${TARGET_NAME} main.cpp)

# find OpenCV
find_package(OpenCV REQUIRED)

# Set path and libraries OpenCV
if(OpenCV_FOUND)
  # include path
  include_directories(${OpenCV_INCLUDE_DIRS})

  # link library path
  target_link_libraries(${TARGET_NAME} ${OpenCV_LIBS})
endif(OpenCV_FOUND)

