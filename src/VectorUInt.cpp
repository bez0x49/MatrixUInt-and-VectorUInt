#include "stdafx.h"
#include "VectorUInt.hpp"

VectorUInt::VectorUInt(size_t size, uint value)
try
  : allocator(new uint[size]),
    size(size),
    codeError(Error::No)
{
    for (size_t i = 0; i < size; i++)
    {
        allocator[i] = value;
    }
}
catch (const std::exception& e)
{
    if (allocator != nullptr)
    {
        delete[] allocator;
        allocator = nullptr;
    }
    codeError = Error::Memory;
    std::cerr << "CTOR caught: " << e.what() << std::endl;
}

VectorUInt::VectorUInt()
  : VectorUInt(1, 0)
{
}

VectorUInt::VectorUInt(size_t size)
  : VectorUInt(size, 0)
{
}

VectorUInt::VectorUInt(const VectorUInt& object)
try
  : allocator(new uint[object.size]),
    size(object.size),
    codeError(object.codeError)
{
    for (size_t i = 0; i < size; i++)
    {
        allocator[i] = object.allocator[i];
    }
}
catch (const std::exception& e)
{
    if (allocator != nullptr)
    {
        delete[] allocator;
        allocator = nullptr;
    }
    codeError = Error::Memory;
    std::cerr << "CTOR copy caught: " << e.what() << std::endl;
}

VectorUInt::~VectorUInt()
{
    if (allocator != nullptr)
        delete[] allocator;
}

unsigned int VectorUInt::sum() const
{
    unsigned int s = 0;
    for (size_t i = 0; i < size; i++)
        s += allocator[i];

    return s;
}

VectorUInt& VectorUInt::operator++()
{
    for (size_t i = 0; i < size; i++)
        ++allocator[i];
    return *this;
}

VectorUInt& VectorUInt::operator--()
{
    for (size_t i = 0; i < size; i++)
        --allocator[i];
    return *this;
}

VectorUInt VectorUInt::operator--(int)
{
    /// Create temporary object with CTOR copy
    VectorUInt tmp(*this);
    /// Use operator prefix increment
    ++(*this);
    /// Return temporary object
    return tmp;
}

bool VectorUInt::operator!() const
{
    return size != 0;
}

VectorUInt VectorUInt::operator++(int)
{
    /// Create temporary object with CTOR copy
    VectorUInt tmp(*this);
    /// Use operator prefix decrement
    --(*this);

    /// Return temporary object
    return tmp;
}

VectorUInt VectorUInt::operator~() const
{
    VectorUInt tmp(*this);
    for (size_t i = 0; i < size; i++)
    {
        tmp.allocator[i] = ~tmp.allocator[i];
    }
    return tmp;
}

VectorUInt VectorUInt::operator-() const
{
    VectorUInt tmp(*this);
    for (size_t i = 0; i < size; i++)
    {
        tmp.allocator[i] = -tmp.allocator[i];
    }
    return tmp;
}

VectorUInt VectorUInt::operator+(const VectorUInt& rhs) const
{
    if (rhs.size != size)
        return VectorUInt{};

    VectorUInt tmp(*this);
    for (size_t i = 0; i < size; i++)
        tmp.allocator[i] = tmp.allocator[i] + rhs.allocator[i];

    return tmp;
}

VectorUInt VectorUInt::operator-(const VectorUInt& rhs) const
{
    if (rhs.size != size)
        return VectorUInt{};

    VectorUInt tmp(*this);
    for (size_t i = 0; i < size; i++)
        tmp.allocator[i] = tmp.allocator[i] - rhs.allocator[i];

    return tmp;
}

VectorUInt VectorUInt::operator*(const VectorUInt& rhs) const
{
    if (rhs.size != size)
        return VectorUInt{};

    VectorUInt tmp(*this);
    for (size_t i = 0; i < size; i++)
        tmp.allocator[i] = tmp.allocator[i] * rhs.allocator[i];

    return tmp;
}

VectorUInt VectorUInt::operator/(const VectorUInt& rhs) const
{
    if (rhs.size != size)
        return VectorUInt{};

    VectorUInt tmp(*this);
    for (size_t i = 0; i < size; i++)
        if (rhs.allocator[i] != 0)
            tmp.allocator[i] = tmp.allocator[i] / rhs.allocator[i];

    return tmp;
}

VectorUInt VectorUInt::operator%(const VectorUInt& rhs) const
{
    if (rhs.size != size)
        return VectorUInt{};

    VectorUInt tmp(*this);
    for (size_t i = 0; i < size; i++)
        if (rhs.allocator[i] != 0)
            tmp.allocator[i] = tmp.allocator[i] % rhs.allocator[i];

    return tmp;
}

VectorUInt VectorUInt::operator+(uint rhs) const
{
    VectorUInt tmp(*this);

    for (size_t i = 0; i < size; i++)
    {
        tmp.allocator[i] = tmp.allocator[i] + rhs;
    }

    return tmp;
}

VectorUInt VectorUInt::operator-(uint rhs) const
{
    VectorUInt tmp(*this);

    for (size_t i = 0; i < size; i++)
    {
        tmp.allocator[i] = tmp.allocator[i] - rhs;
    }

    return tmp;
}

VectorUInt VectorUInt::operator*(uint rhs) const
{
    VectorUInt tmp(*this);

    for (size_t i = 0; i < size; i++)
    {
        tmp.allocator[i] = tmp.allocator[i] * rhs;
    }

    return tmp;
}

VectorUInt VectorUInt::operator/(uint rhs) const
{
    VectorUInt tmp(*this);

    for (size_t i = 0; i < size; i++)
    {
        if (rhs != 0)
            tmp.allocator[i] = tmp.allocator[i] / rhs;
    }

    return tmp;
}

VectorUInt VectorUInt::operator%(uint rhs) const
{
    VectorUInt tmp(*this);

    for (size_t i = 0; i < size; i++)
    {
        if (rhs != 0)
            tmp.allocator[i] = tmp.allocator[i] % rhs;
    }

    return tmp;
}

VectorUInt& VectorUInt::operator=(const VectorUInt& rhs)
{
    if (allocator != nullptr)
        delete[] allocator;

    codeError = rhs.codeError;
    size = rhs.size;
    for (size_t i = 0; i < size; i++)
        allocator[i] = rhs.allocator[i];

    return *this;
}

VectorUInt& VectorUInt::operator+=(const VectorUInt& rhs)
{
    if (size != rhs.size)
        return *this;

    for (size_t i = 0; i < size; i++)
        allocator[i] += rhs.allocator[i];

    return *this;
}

VectorUInt& VectorUInt::operator-=(const VectorUInt& rhs)
{
    if (size != rhs.size)
        return *this;

    for (size_t i = 0; i < size; i++)
        allocator[i] -= rhs.allocator[i];

    return *this;
}

VectorUInt& VectorUInt::operator*=(const VectorUInt& rhs)
{
    if (size != rhs.size)
        return *this;

    for (size_t i = 0; i < size; i++)
        allocator[i] *= rhs.allocator[i];

    return *this;
}

VectorUInt& VectorUInt::operator/=(const VectorUInt& rhs)
{
    if (size != rhs.size)
        return *this;

    for (size_t i = 0; i < size; i++)
        if (rhs.allocator[i] != 0)
            allocator[i] /= rhs.allocator[i];

    return *this;
}

VectorUInt& VectorUInt::operator%=(const VectorUInt& rhs)
{
    if (size != rhs.size)
        return *this;

    for (size_t i = 0; i < size; i++)
        if (rhs.allocator[i] != 0)
            allocator[i] %= rhs.allocator[i];

    return *this;
}

VectorUInt& VectorUInt::operator+=(uint rhs)
{
    for (size_t i = 0; i < size; i++)
        allocator[i] += rhs;

    return *this;
}

VectorUInt& VectorUInt::operator-=(uint rhs)
{
    for (size_t i = 0; i < size; i++)
        allocator[i] -= rhs;

    return *this;
}

VectorUInt& VectorUInt::operator*=(uint rhs)
{
    for (size_t i = 0; i < size; i++)
        allocator[i] *= rhs;

    return *this;
}

VectorUInt& VectorUInt::operator/=(uint rhs)
{
    if (rhs == 0)
        return *this;

    for (size_t i = 0; i < size; i++)
        allocator[i] /= rhs;

    return *this;
}

VectorUInt& VectorUInt::operator%=(uint rhs)
{
    if (rhs == 0)
        return *this;

    for (size_t i = 0; i < size; i++)
        allocator[i] %= rhs;

    return *this;
}

VectorUInt& VectorUInt::operator&=(uint rhs)
{
    for (size_t i = 0; i < size; i++)
        allocator[i] &= rhs;

    return *this;
}

VectorUInt& VectorUInt::operator&=(const VectorUInt& rhs)
{
    for (size_t i = 0; i < size; i++)
        allocator[i] &= rhs.allocator[i];

    return *this;
}

VectorUInt& VectorUInt::operator|=(uint rhs)
{
    for (size_t i = 0; i < size; i++)
        allocator[i] |= rhs;

    return *this;
}

VectorUInt& VectorUInt::operator^=(uint rhs)
{
    for (size_t i = 0; i < size; i++)
        allocator[i] ^= rhs;

    return *this;
}

VectorUInt& VectorUInt::operator|=(const VectorUInt& rhs)
{
    for (size_t i = 0; i < size; i++)
        allocator[i] |= rhs.allocator[i];

    return *this;
}

VectorUInt& VectorUInt::operator^=(const VectorUInt& rhs)
{
    for (size_t i = 0; i < size; i++)
        allocator[i] ^= rhs.allocator[i];

    return *this;
}

VectorUInt operator&(const VectorUInt& lhs, const VectorUInt& rhs)
{
    if (lhs.size != rhs.size)
        return VectorUInt{};

    VectorUInt tmp(lhs);

    for (size_t i = 0; i < lhs.size; i++)
        tmp.allocator[i] = lhs.allocator[i] & rhs.allocator[i];

    return tmp;
}

VectorUInt operator^(const VectorUInt& lhs, const VectorUInt& rhs)
{
    if (lhs.size != rhs.size)
        return VectorUInt{};

    VectorUInt tmp(lhs);

    for (size_t i = 0; i < lhs.size; i++)
        tmp.allocator[i] = lhs.allocator[i] ^ rhs.allocator[i];

    return tmp;
}

VectorUInt operator|(const VectorUInt& lhs, const VectorUInt& rhs)
{
    if (lhs.size != rhs.size)
        return VectorUInt{};

    VectorUInt tmp(lhs);

    for (size_t i = 0; i < lhs.size; i++)
        tmp.allocator[i] = lhs.allocator[i] | rhs.allocator[i];

    return tmp;
}

VectorUInt operator&(const VectorUInt& lhs, uint rhs)
{
    VectorUInt tmp(lhs);

    for (size_t i = 0; i < lhs.size; i++)
        tmp.allocator[i] = lhs.allocator[i] & rhs;

    return tmp;
}

VectorUInt operator^(const VectorUInt& lhs, uint rhs)
{
    VectorUInt tmp(lhs);

    for (size_t i = 0; i < lhs.size; i++)
        tmp.allocator[i] = lhs.allocator[i] ^ rhs;

    return tmp;
}

VectorUInt operator|(const VectorUInt& lhs, uint rhs)
{
    VectorUInt tmp(lhs);

    for (size_t i = 0; i < lhs.size; i++)
        tmp.allocator[i] = lhs.allocator[i] | rhs;

    return tmp;
}

std::ostream& operator<<(std::ostream& os, const VectorUInt& rhs)
{
    for (size_t i = 0; i < rhs.len(); i++)
        os << rhs[i] << ' ';
    return os;
}

std::istream& operator>>(std::istream& is, VectorUInt& rhs)
{
    for (size_t i = 0; i < rhs.len(); i++)
        is >> rhs[i];
    return is;
}

unsigned int& VectorUInt::operator[](size_t index) const
{
    if (index > size)
    {
        codeError = Error::Range;
        return allocator[size - 1];
    }

    return allocator[index];
}

bool operator==(const VectorUInt& lhs, const VectorUInt& rhs)
{
    if (lhs.len() != rhs.len())
        return false;

    VectorUInt temp1(lhs), temp2(rhs);

    std::sort(temp1.allocator, temp1.allocator + temp1.len());
    std::sort(temp2.allocator, temp2.allocator + temp2.len());

    for (size_t i = 0; i < lhs.len(); i++)
        if (temp1[i] != temp2[i])
            return false;

    return true;
}

bool operator!=(const VectorUInt& lhs, const VectorUInt& rhs)
{
    if (lhs.len() != rhs.len())
        return true;

    return !(lhs == rhs);
}

bool operator<(const VectorUInt& lhs, const VectorUInt& rhs)
{
    return lhs.sum() < rhs.sum();
}

bool operator>(const VectorUInt& lhs, const VectorUInt& rhs)
{
    return rhs < lhs;
}

bool operator>=(const VectorUInt& lhs, const VectorUInt& rhs)
{
    return !(lhs < rhs);
}

bool operator<=(const VectorUInt& lhs, const VectorUInt& rhs)
{
    return !(lhs > rhs);
}