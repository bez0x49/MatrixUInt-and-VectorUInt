#pragma once
#include "VectorUInt.hpp"

/**
 * @brief Implementation class Matrix for unsigned int.
 */
class MatrixUInt
{
    /// Array of vectors
    VectorUInt* UIntArray;

    /**********
     * SIZES: *
     **********/

    /// Size of each vector
    size_t n;
    /// Size of array
    size_t size;
    /// Error status
    mutable Error codeError{Error::No};

  public:
    /**********
     * CTORS: *
     **********/

    /**
     * @brief Assignment array nullptr, initialize n, size to zero. 
     * Assignment codeError Error::No.
     */
    MatrixUInt();

    /**
     * @brief Create Matrix nxn.
     * 
     * @param size Size of matrix
     */
    MatrixUInt(size_t size);

    /**
     * @brief Create matrix nxm and initialize elements to 0.
     * 
     * @param rows Count of rows
     * @param columns Count of columns
     */
    MatrixUInt(size_t rows, size_t columns);

    /**
     * @brief Create matrix nxm and initialize to value.
     * 
     * @param rows      Count of rows
     * @param columns   Count of columns
     * @param value     Value to initialize
     */
    MatrixUInt(size_t rows, size_t columns, uint value);

    MatrixUInt(const MatrixUInt& object);

    /**
     * @brief DTOR: Free allocated memory.
     */
    ~MatrixUInt();

    /************
     * GETTERS: *
     ************/

    /**
     * @brief Return the sum of elements of matrix.
     * 
     * @return Sum of elements
     */
    unsigned int sum() const;

    /**
     * @brief Get the size
     * 
     * @return Count of rows
     */
    constexpr size_t getSize()
    {
        return size;
    }

    /**
     * @brief Get the n
     * 
     * @return Count of columns
     */
    constexpr size_t getN()
    {
        return n;
    }

    /**
     * @brief Get the code Error
     * 
     * @return Error status 
     */
    Error getError()
    {
        return codeError;
    }

    /***************************
     * OVERLOADING: OPERATORS: *
     ***************************/

    MatrixUInt& operator++();
    MatrixUInt& operator--();

    MatrixUInt operator++(int);
    MatrixUInt operator--(int);

    bool operator!() const
    {
        return n == size;
    }

    MatrixUInt operator~() const;
    MatrixUInt operator-() const;

    MatrixUInt operator+(const MatrixUInt& rhs) const;
    MatrixUInt operator-(const MatrixUInt& rhs) const;
    MatrixUInt operator*(const MatrixUInt& rhs) const;
    MatrixUInt operator/(const MatrixUInt& rhs) const;
    MatrixUInt operator%(const MatrixUInt& rhs) const;

    friend MatrixUInt operator&(const MatrixUInt& lhs, const MatrixUInt& rhs);
    friend MatrixUInt operator^(const MatrixUInt& lhs, const MatrixUInt& rhs);
    friend MatrixUInt operator|(const MatrixUInt& lhs, const MatrixUInt& rhs);

    MatrixUInt operator+(uint rhs) const;
    MatrixUInt operator-(uint rhs) const;
    MatrixUInt operator*(uint rhs) const;
    MatrixUInt operator/(uint rhs) const;
    MatrixUInt operator%(uint rhs) const;

    friend MatrixUInt operator&(const MatrixUInt& lhs, uint rhs);
    friend MatrixUInt operator^(const MatrixUInt& lhs, uint rhs);
    friend MatrixUInt operator|(const MatrixUInt& lhs, uint rhs);

    MatrixUInt& operator=(const MatrixUInt& rhs);
    MatrixUInt& operator+=(const MatrixUInt& rhs);
    MatrixUInt& operator-=(const MatrixUInt& rhs);
    MatrixUInt& operator*=(const MatrixUInt& rhs);
    MatrixUInt& operator/=(const MatrixUInt& rhs);
    MatrixUInt& operator%=(const MatrixUInt& rhs);

    MatrixUInt& operator&=(const MatrixUInt& rhs);
    MatrixUInt& operator^=(const MatrixUInt& rhs);
    MatrixUInt& operator|=(const MatrixUInt& rhs);

    MatrixUInt& operator+=(uint rhs);
    MatrixUInt& operator-=(uint rhs);
    MatrixUInt& operator*=(uint rhs);
    MatrixUInt& operator/=(uint rhs);
    MatrixUInt& operator%=(uint rhs);

    MatrixUInt& operator&=(uint rhs);
    MatrixUInt& operator^=(uint rhs);
    MatrixUInt& operator|=(uint rhs);

    friend std::ostream& operator<<(std::ostream& os, const MatrixUInt& rhs);
    friend std::istream& operator>>(std::istream& is, MatrixUInt& rhs);

    VectorUInt& operator[](size_t index) const;

    friend bool operator==(const MatrixUInt& lhs, const MatrixUInt& rhs);
    friend bool operator!=(const MatrixUInt& lhs, const MatrixUInt& rhs);
    friend bool operator>(const MatrixUInt& lhs, const MatrixUInt& rhs);
    friend bool operator>=(const MatrixUInt& lhs, const MatrixUInt& rhs);
    friend bool operator<(const MatrixUInt& lhs, const MatrixUInt& rhs);
    friend bool operator<=(const MatrixUInt& lhs, const MatrixUInt& rhs);

    // TODO: overloading operator *, *= for VectorUInt

  public:
    /// Count of matrices
    static size_t numMatrices;
};