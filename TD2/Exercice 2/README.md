# Matrix Numerical Operations

This project demonstrates basic matrix operations, including addition, multiplication, determinant calculation, and matrix inversion. It uses C++ classes to handle matrices with numerical values (integers, floats, etc.) and supports operations such as matrix arithmetic and computing the inverse using the cofactor method.

## Features
- Matrix creation and element access
- Matrix addition (`+`), subtraction (`-`), multiplication (`*`), and division (`/`)
- Determinant calculation
- Inverse matrix calculation (for square matrices)
- Identity matrix creation

## Files
- **MatrixBase.h**: Defines the base class for matrix handling, including element access and display.
- **MatrixNumerical.h**: Defines a template-based class inheriting from `MatrixBase` for numerical matrices.
- **MatrixNumerical.cpp**: Contains the implementation of `MatrixNumerical` methods such as determinant and inverse calculation.
- **main.cpp**: The main program demonstrating the use of the `MatrixNumerical` class with matrix operations.

## How to Build
You can build the project using the provided `build.sh` script or by manually compiling the files with `g++`.

### Option 1: Using the `build.sh` script
Run the following command in the terminal:

```bash
./build.sh

