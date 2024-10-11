# Searching Algorithms

This project implements three search algorithms (`LinearSearch`, `JumpSearch`, and `BinarySearch`) in C++. The code includes a base class `SearchingAlgorithm` that tracks the number of comparisons made during the search process.

## Features
- **Linear Search**: A simple search algorithm that checks each element sequentially.
- **Jump Search**: A search algorithm that jumps ahead by a fixed step size and then performs a linear search in the relevant segment.
- **Binary Search**: A fast search algorithm that divides the sorted array in half to find the target.

## Prerequisites

To build and run this project, you need:
- A C++ compiler supporting C++11 (e.g., GCC or Clang).

## How to Build and Run

1. Clone the repository or download the source files.

2. Navigate to the project directory.

3. To compile the program, run the following command from the terminal:

   ```bash
   ./build.sh
