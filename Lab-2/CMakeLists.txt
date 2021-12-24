cmake_minimum_required(VERSION 3.19)
project(lab2)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab2 main.cpp Sequence/Sequence.hpp Sequence/ArraySequence.hpp Sequence/DynamicArray.hpp Sequence/ListSequence.hpp Sequence/LinkedList.hpp Histogram/IDictionary.hpp Histogram/Histogram.hpp Histogram/Sort.hpp Histogram/DictNode.hpp Histogram/Dict.hpp Paginator/Paginator.hpp SubExpression/SubExpression.hpp Keyboard_Tests.hpp SubExpression/SubExpressionTests.hpp Paginator/PaginatorAutoTest.hpp)