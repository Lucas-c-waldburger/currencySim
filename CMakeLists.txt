cmake_minimum_required(VERSION 3.24)
project(currencySim)

set(CMAKE_CXX_STANDARD 17)

add_executable(currencySim main.cpp Currency.cpp Currency.h Money.cpp Money.h LinkedList.cpp LinkedList.h Stack.cpp Stack.h Queue.cpp Queue.h BSTNode.cpp BSTNode.h BSTLinkList.cpp BSTLinkList.h)
