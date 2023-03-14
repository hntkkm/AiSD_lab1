cmake_minimum_required(VERSION 3.23)
project(lab1aisd C)

set(CMAKE_C_STANDARD 99)

add_executable(lab1aisd main.c doublyLinkedList.c doublyLinkedList.h singlyLinkedList.c singlyLinkedList.h fifo.c fifo.h lifo.c lifo.h)
