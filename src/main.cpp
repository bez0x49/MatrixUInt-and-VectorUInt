#include "stdafx.h"
#include "MatrixUInt.hpp"

int main()
{
    VectorUInt A{5, 3};
    VectorUInt B{5, 4};

    std::cout << A << std::endl;
    std::cout << B << std::endl;
    std::cout << A + B << std::endl;

    VectorUInt C = B - A;

    VectorUInt *D = new VectorUInt;
    std::cout << *D << std::endl;
    delete D;

    std::cout << C << std::endl;
    std::cout << ++C << std::endl;

    MatrixUInt M{5, 5, 5};
    MatrixUInt Q{5, 5, 5};

    std::cout << M << std::endl;
    std::cout << Q << std::endl;
    std::cout << "matrices: " << MatrixUInt::numMatrices << std::endl;

    std::cout << "M == Q: " << std::boolalpha << (M == Q) << std::endl;

    MatrixUInt R = M * Q;
    std::cout << R << std::endl;
    std::cout << "matrices: " << MatrixUInt::numMatrices << std::endl;

    return EXIT_SUCCESS;
}