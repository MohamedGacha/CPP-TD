#include "MatrixNumerical.h"

int main() {
    MatrixNumerical<int> matrix1(2, 2);
    matrix1.addElement(0, 0, 1);
    matrix1.addElement(0, 1, 2);
    matrix1.addElement(1, 0, 3);
    matrix1.addElement(1, 1, 4);

    MatrixNumerical<int> matrix2(2, 2);
    matrix2.addElement(0, 0, 5);
    matrix2.addElement(0, 1, 6);
    matrix2.addElement(1, 0, 7);
    matrix2.addElement(1, 1, 8);

    MatrixNumerical<int> sum = matrix1 + matrix2;

    std::cout << "Matrix 1:" << std::endl;
    matrix1.display();

    std::cout << "Matrix 2:" << std::endl;
    matrix2.display();

    std::cout << "Sum of Matrix 1 and Matrix 2:" << std::endl;
    sum.display();

    MatrixNumerical<int> identity = MatrixNumerical<int>::getIdentity(3);
    std::cout << "Identity Matrix of size 3:" << std::endl;
    identity.display();

    return 0;
}
