cmake_minimum_required(VERSION 3.19)
project(lab2)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab2 main.cpp Sequence/Sequence.hpp Sequence/ArraySequence.hpp Sequence/DynamicArray.hpp Sequence/ListSequence.hpp Sequence/LinkedList.hpp IDictionary.hpp Histogram.hpp Sort.hpp DictNode.hpp Dict.hpp)