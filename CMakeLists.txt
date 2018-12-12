cmake_minimum_required(VERSION 3.6)
project(first_clion)

set(CMAKE_CXX_STANDARD 14)
set(GRAPHVIZ_INCLUDE_DIR "C:\\Program Files (x86)\\Graphviz2.38\\include\\graphviz")
set(GRAPHVIZ_LIB_DIR "C:/Program Files x86)/Graphviz2.38/lib/release/lib")

include_directories("${GRAPHVIZ_INCLUDE_DIR}")
link_directories("C:/Program Files (x86)/Graphviz2.38/lib/release/lib")

set(SOURCE_FILES main.cpp Tree.h Tree.cpp Akinator.h Akinator.cpp)

add_executable(first_clion ${SOURCE_FILES})

target_link_libraries(first_clion gvc)