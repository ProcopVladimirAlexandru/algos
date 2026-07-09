#!/bin/bash

set -e
g++ -o main.out ./main.cpp ./testers/SortingTester.cpp ./testers/SearchTester.cpp ./utils/PVAFile.cpp ./utils/VectorOperations.cpp ./base_sort/BaseSort.cpp ./bubble_sort/BubbleSort.cpp ./selection_sort/SelectionSort.cpp ./insertion_sort/InsertionSort.cpp ./binary_search/BinarySearch.cpp -I./utils -I./base_sort -I./bubble_sort -I./selection_sort -I./insertion_sort -I./binary_search -lstdc++;./main.out