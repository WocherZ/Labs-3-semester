cmake_minimum_required(VERSION 3.19)
project(lab3)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab3 main.cpp Matrix/IDictionary.hpp Matrix/DictNode.hpp Matrix/Dict.hpp Matrix/Matrix.hpp Sequence/Sequence.hpp Sequence/ArraySequence.hpp Sequence/DynamicArray.hpp Sequence/ListSequence.hpp Sequence/LinkedList.hpp Graphs/TestGraph.hpp Graphs/Graph.hpp Graphs/DirectedGraph.hpp Graphs/HelperGraph.hpp Graphs/TestDirectedGraph.hpp)