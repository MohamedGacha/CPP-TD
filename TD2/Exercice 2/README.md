# Matrix Program

This project defines a matrix library in C++ that includes classes for matrix operations. The library consists of two main classes: `MatrixBase` for general matrix functionality and `MatrixNumerical` for specific operations on numerical matrices.

## Features

- Define a 2D matrix with template support.
- Perform basic operations like addition, subtraction, multiplication, and division.
- Calculate determinants and inverses of numerical matrices.
- Generate identity matrices.

## Class Definitions

1. **MatrixBase**: 
   - Contains data, rows, and cols.
   - Functions:
     - `addElement`: Add an element to the matrix.
     - `getElement`: Retrieve an element from the matrix.
     - `getRows`: Get the number of rows.
     - `getCols`: Get the number of columns.
     - `Display`: Display the matrix.

2. **MatrixNumerical** (inherits from `MatrixBase`): 
   - Specializes in numerical values (int, double, float).
   - Functions:
     - `getDeterminant`: Calculate the determinant.
     - Overloaded operators `+`, `-`, `*`, and `/`.
     - `getInverse`: Calculate the inverse using the cofactor method.
     - Static function `getIdentity`: Generate an identity matrix.

## Build Instructions

To build the program, you can use the provided `build.sh` script. Follow the steps below:

### Prerequisites

Ensure you have the following installed:
- A C++ compiler (e.g., g++, clang++)
- Make (if using makefiles)

### Steps to Build

1. Clone the repository:

   ```bash
   git clone <repository_url>
   cd <repository_directory>
