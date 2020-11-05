#include "stdafx.h"
#include "MatrixUInt.hpp"

// Count of matrices
size_t MatrixUInt::numMatrices = 0;

MatrixUInt::MatrixUInt()
  : UIntArray(nullptr)
  , n(0)
  , size(0)
  , codeError(Error::No)
{
    numMatrices++;
}

MatrixUInt::MatrixUInt(size_t size)
  : MatrixUInt(size, size, 0)
{
}

MatrixUInt::MatrixUInt(size_t rows, size_t columns)
  : MatrixUInt(rows, columns, 0)
{
}

MatrixUInt::MatrixUInt(size_t rows, size_t columns, uint value)
try
  : UIntArray(new VectorUInt[rows]),
    n(columns),
    size(rows),
    codeError(Error::No)
{
    for (size_t i = 0; i < size; i++)
    {
        UIntArray[i] = VectorUInt(columns, value);
    }
    numMatrices++;
}
catch (const std::exception& e)
{
    if (UIntArray != nullptr)
    {
        delete[] UIntArray;
        UIntArray = nullptr;
    }
    numMatrices--;
    codeError = Error::Memory;
    std::cerr << "CTOR: " << e.what() << std::endl;
}

MatrixUInt::MatrixUInt(const MatrixUInt& object)
try
  : UIntArray(new VectorUInt[object.size]),
    size(object.size),
    n(object.n),
    codeError(object.codeError)
{
    for (size_t i = 0; i < size; i++)
    {
        UIntArray[i] = object.UIntArray[i];
    }
    numMatrices++;
}
catch (const std::exception& e)
{
    if (UIntArray != nullptr)
    {
        delete[] UIntArray;
        UIntArray = nullptr;
    }
    codeError = Error::Memory;
    std::cerr << "CTOR copy: " << e.what() << std::endl;
}

MatrixUInt::~MatrixUInt()
{
    if (UIntArray != nullptr)
        delete[] UIntArray;
    numMatrices--;
}

MatrixUInt& MatrixUInt::operator--()
{
    for (size_t i = 0; i < size; i++)
    {
        --UIntArray[i];
    }

    return *this;
}

MatrixUInt MatrixUInt::operator--(int)
{
    MatrixUInt tmp(*this);

    --(*this);

    return tmp;
}

MatrixUInt MatrixUInt::operator~() const
{
    MatrixUInt tmp(*this);

    for (size_t i = 0; i < size; i++)
    {
        tmp.UIntArray[i] = ~tmp.UIntArray[i];
    }

    return tmp;
}

MatrixUInt MatrixUInt::operator-() const
{
    MatrixUInt tmp(*this);

    for (size_t i = 0; i < size; i++)
    {
        tmp.UIntArray[i] = -tmp.UIntArray[i];
    }

    return tmp;
}

MatrixUInt MatrixUInt::operator++(int)
{
    MatrixUInt tmp(*this);

    ++(*this);

    return tmp;
}

MatrixUInt& MatrixUInt::operator++()
{
    for (size_t i = 0; i < size; i++)
    {
        ++UIntArray[i];
    }

    return *this;
}

MatrixUInt MatrixUInt::operator+(const MatrixUInt& rhs) const
{
    if (rhs.size != size && rhs.n != n)
        return MatrixUInt{};

    MatrixUInt tmp(*this);

    for (size_t i = 0; i < size; i++)
    {
        tmp.UIntArray[i] = tmp.UIntArray[i] + rhs.UIntArray[i];
    }

    return tmp;
}

MatrixUInt MatrixUInt::operator-(const MatrixUInt& rhs) const
{
    if (rhs.size != size && rhs.n != n)
        return MatrixUInt{};

    MatrixUInt tmp(*this);

    for (size_t i = 0; i < size; i++)
    {
        tmp.UIntArray[i] = tmp.UIntArray[i] - rhs.UIntArray[i];
    }

    return tmp;
}

MatrixUInt MatrixUInt::operator*(const MatrixUInt& rhs) const
{
    if (n != rhs.size)
        return MatrixUInt{};

    MatrixUInt tmp(n, size);

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            double sum = 0;
            for (size_t k = 0; k < size; k++)
            {
                sum += UIntArray[i][k] + rhs.UIntArray[k][i];
            }
            tmp[i][j] = sum;
        }
    }

    return tmp;
}

MatrixUInt MatrixUInt::operator/(const MatrixUInt& rhs) const
{
    if (rhs.size != size && rhs.n != n)
        return MatrixUInt{};

    MatrixUInt tmp(*this);

    for (size_t i = 0; i < size; i++)
    {
        tmp.UIntArray[i] = tmp.UIntArray[i] / rhs.UIntArray[i];
    }

    return tmp;
}

MatrixUInt MatrixUInt::operator%(const MatrixUInt& rhs) const
{
    if (rhs.size != size && rhs.n != n)
        return MatrixUInt{};

    MatrixUInt tmp(*this);

    for (size_t i = 0; i < size; i++)
    {
        tmp.UIntArray[i] = tmp.UIntArray[i] % rhs.UIntArray[i];
    }

    return tmp;
}

MatrixUInt MatrixUInt::operator+(uint rhs) const
{
    MatrixUInt tmp(*this);

    for (size_t i = 0; i < size; i++)
    {
        tmp.UIntArray[i] = tmp.UIntArray[i] + rhs;
    }

    return tmp;
}

MatrixUInt MatrixUInt::operator-(uint rhs) const
{
    MatrixUInt tmp(*this);

    for (size_t i = 0; i < size; i++)
    {
        tmp.UIntArray[i] = tmp.UIntArray[i] - rhs;
    }

    return tmp;
}

MatrixUInt MatrixUInt::operator*(uint rhs) const
{
    MatrixUInt tmp(*this);

    for (size_t i = 0; i < size; i++)
    {
        tmp.UIntArray[i] = tmp.UIntArray[i] * rhs;
    }

    return tmp;
}

MatrixUInt MatrixUInt::operator/(uint rhs) const
{
    MatrixUInt tmp(*this);

    for (size_t i = 0; i < size; i++)
    {
        tmp.UIntArray[i] = tmp.UIntArray[i] / rhs;
    }

    return tmp;
}

MatrixUInt MatrixUInt::operator%(uint rhs) const
{
    MatrixUInt tmp(*this);

    for (size_t i = 0; i < size; i++)
    {
        tmp.UIntArray[i] = tmp.UIntArray[i] % rhs;
    }

    return tmp;
}

VectorUInt& MatrixUInt::operator[](size_t index) const
{
    if (index > size)
    {
        codeError = Error::Range;
        return UIntArray[size - 1];
    }

    return UIntArray[index];
}

MatrixUInt operator&(const MatrixUInt& lhs, uint rhs)
{
    MatrixUInt tmp(lhs);

    for (size_t i = 0; i < lhs.size; i++)
    {
        tmp.UIntArray[i] = tmp.UIntArray[i] & rhs;
    }

    return tmp;
}

MatrixUInt operator^(const MatrixUInt& lhs, uint rhs)
{
    MatrixUInt tmp(lhs);

    for (size_t i = 0; i < lhs.size; i++)
    {
        tmp.UIntArray[i] = tmp.UIntArray[i] ^ rhs;
    }

    return tmp;
}

MatrixUInt operator|(const MatrixUInt& lhs, uint rhs)
{
    MatrixUInt tmp(lhs);

    for (size_t i = 0; i < lhs.size; i++)
    {
        tmp.UIntArray[i] = tmp.UIntArray[i] | rhs;
    }

    return tmp;
}

MatrixUInt operator&(const MatrixUInt& lhs, const MatrixUInt& rhs)
{
    if (lhs.size != rhs.size && lhs.n != rhs.n)
        return MatrixUInt{};

    MatrixUInt tmp(lhs);

    for (size_t i = 0; i < lhs.size; i++)
    {
        tmp.UIntArray[i] = lhs.UIntArray[i] & rhs.UIntArray[i];
    }

    return tmp;
}

MatrixUInt operator^(const MatrixUInt& lhs, const MatrixUInt& rhs)
{
    if (lhs.size != rhs.size && lhs.n != rhs.n)
        return MatrixUInt{};

    MatrixUInt tmp(lhs);

    for (size_t i = 0; i < lhs.size; i++)
    {
        tmp.UIntArray[i] = lhs.UIntArray[i] ^ rhs.UIntArray[i];
    }

    return tmp;
}

MatrixUInt operator|(const MatrixUInt& lhs, const MatrixUInt& rhs)
{
    if (lhs.size != rhs.size && lhs.n != rhs.n)
        return MatrixUInt{};

    MatrixUInt tmp(lhs);

    for (size_t i = 0; i < lhs.size; i++)
    {
        tmp.UIntArray[i] = lhs.UIntArray[i] | rhs.UIntArray[i];
    }

    return tmp;
}

MatrixUInt& MatrixUInt::operator=(const MatrixUInt& rhs)
{
    if (UIntArray != nullptr)
        delete[] UIntArray;

    codeError = rhs.codeError;
    size = rhs.size;
    for (size_t i = 0; i < size; i++)
        UIntArray[i] = rhs.UIntArray[i];

    return *this;
}

MatrixUInt& MatrixUInt::operator+=(const MatrixUInt& rhs)
{
    if (size != rhs.size && n != rhs.n)
        return *this;

    for (size_t i = 0; i < size; i++)
    {
        UIntArray[i] += rhs.UIntArray[i];
    }

    return *this;
}

MatrixUInt& MatrixUInt::operator-=(const MatrixUInt& rhs)
{
    if (size != rhs.size && n != rhs.n)
        return *this;

    for (size_t i = 0; i < size; i++)
    {
        UIntArray[i] -= rhs.UIntArray[i];
    }

    return *this;
}

MatrixUInt& MatrixUInt::operator*=(const MatrixUInt& rhs)
{
    *this = (*this) * rhs;
    return *this;
}

MatrixUInt& MatrixUInt::operator/=(const MatrixUInt& rhs)
{
    if (size != rhs.size && n != rhs.n)
        return *this;

    for (size_t i = 0; i < size; i++)
    {
        UIntArray[i] /= rhs.UIntArray[i];
    }

    return *this;
}

MatrixUInt& MatrixUInt::operator%=(const MatrixUInt& rhs)
{
    if (size != rhs.size && n != rhs.n)
        return *this;

    for (size_t i = 0; i < size; i++)
    {
        UIntArray[i] %= rhs.UIntArray[i];
    }

    return *this;
}

MatrixUInt& MatrixUInt::operator&=(const MatrixUInt& rhs)
{
    if (size != rhs.size && n != rhs.n)
        return *this;

    for (size_t i = 0; i < size; i++)
    {
        UIntArray[i] &= rhs.UIntArray[i];
    }

    return *this;
}

MatrixUInt& MatrixUInt::operator^=(const MatrixUInt& rhs)
{
    if (size != rhs.size && n != rhs.n)
        return *this;

    for (size_t i = 0; i < size; i++)
    {
        UIntArray[i] ^= rhs.UIntArray[i];
    }

    return *this;
}

MatrixUInt& MatrixUInt::operator|=(const MatrixUInt& rhs)
{
    if (size != rhs.size && n != rhs.n)
        return *this;

    for (size_t i = 0; i < size; i++)
    {
        UIntArray[i] |= rhs.UIntArray[i];
    }

    return *this;
}

MatrixUInt& MatrixUInt::operator+=(uint rhs)
{
    for (size_t i = 0; i < size; i++)
    {
        UIntArray[i] += rhs;
    }

    return *this;
}

MatrixUInt& MatrixUInt::operator-=(uint rhs)
{
    for (size_t i = 0; i < size; i++)
    {
        UIntArray[i] -= rhs;
    }

    return *this;
}

MatrixUInt& MatrixUInt::operator*=(uint rhs)
{
    for (size_t i = 0; i < size; i++)
    {
        UIntArray[i] *= rhs;
    }

    return *this;
}

MatrixUInt& MatrixUInt::operator/=(uint rhs)
{
    for (size_t i = 0; i < size; i++)
    {
        UIntArray[i] /= rhs;
    }

    return *this;
}

MatrixUInt& MatrixUInt::operator%=(uint rhs)
{
    for (size_t i = 0; i < size; i++)
    {
        UIntArray[i] %= rhs;
    }

    return *this;
}

MatrixUInt& MatrixUInt::operator&=(uint rhs)
{
    for (size_t i = 0; i < size; i++)
    {
        UIntArray[i] &= rhs;
    }

    return *this;
}

MatrixUInt& MatrixUInt::operator^=(uint rhs)
{
    for (size_t i = 0; i < size; i++)
    {
        UIntArray[i] ^= rhs;
    }

    return *this;
}

MatrixUInt& MatrixUInt::operator|=(uint rhs)
{
    for (size_t i = 0; i < size; i++)
    {
        UIntArray[i] |= rhs;
    }

    return *this;
}

std::ostream& operator<<(std::ostream& os, const MatrixUInt& rhs)
{
    for (size_t i = 0; i < rhs.size; i++)
    {
        os << rhs.UIntArray[i];
    }
    return os;
}

std::istream& operator>>(std::istream& is, MatrixUInt& rhs)
{
    for (size_t i = 0; i < rhs.size; i++)
    {
        is >> rhs.UIntArray[i];
    }
    return is;
}

unsigned int MatrixUInt::sum() const
{
    unsigned int s = 0;
    for (size_t i = 0; i < size; i++)
        s += UIntArray[i].sum();

    return s;
}

bool operator==(const MatrixUInt& lhs, const MatrixUInt& rhs)
{
    if (lhs.size != rhs.size && lhs.n != rhs.n)
        return false;

    for (size_t i = 0; i < lhs.size; i++)
    {
        if (lhs.UIntArray[i] != rhs.UIntArray[i])
            return false;
    }

    return true;
}

bool operator!=(const MatrixUInt& lhs, const MatrixUInt& rhs)
{
    return !(lhs == rhs);
}

bool operator>(const MatrixUInt& lhs, const MatrixUInt& rhs)
{
    return (lhs.sum() > rhs.sum());
}

bool operator>=(const MatrixUInt& lhs, const MatrixUInt& rhs)
{
    return !(lhs < rhs);
}

bool operator<(const MatrixUInt& lhs, const MatrixUInt& rhs)
{
    return (rhs > lhs);
}

bool operator<=(const MatrixUInt& lhs, const MatrixUInt& rhs)
{
    return !(lhs > rhs);
}

void* MatrixUInt::operator new(size_t size)
{
    return ::new MatrixUInt();
}

void MatrixUInt::operator delete(void* pointer)
{
    free(pointer);
}