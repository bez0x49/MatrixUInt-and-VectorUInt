#pragma once
#include "Error.h"
#include <fstream>

/**
 * @brief Implementation vector for unsigned int,
 * based on a pointer to unsigned int.
 */
class VectorUInt
{
    /// Allocator for elements
    uint* allocator;
    // Size of vector
    size_t size;
    /// Error status
    mutable Error codeError;

  public:
    /**
     * @brief CTOR without parameters. Allocates memory for an element
     * and initializes elements to zero.
     */
    VectorUInt();

    /**
     * @brief CTOR with a parameter. Allocates memory for `size` elements,
     * and initializes them to zero.
     * 
     * @param size Length of vector
     */
    VectorUInt(size_t size);

    /**
     * @brief CTOR with 2 parameters. Allocates memory for `size` elements,
     * and initializes them to `value`.
     * 
     * @param size Length of vector
     * @param value Value for initialization
     */
    VectorUInt(size_t size, uint value);

    /**
     * @brief CTOR copy.
     * @param object - Initialized vector
     */
    VectorUInt(const VectorUInt& object);

    /**
     * @brief DTOR. Free allocated memory.
     */
    ~VectorUInt();

    /**
     * @brief Returns the length of vector.
     */
    constexpr size_t len() const
    {
        return size;
    };

    /**
     * @brief Return the sum of elements of vector.
     * 
     * @return Sum of elements
     */
    unsigned int sum() const;

    /********************************
     * @brief Overloading operators.*
     ********************************/

    VectorUInt& operator++();
    VectorUInt& operator--();

    VectorUInt operator++(int);
    VectorUInt operator--(int);

    bool operator!() const;

    VectorUInt operator~() const;
    VectorUInt operator-() const;

    VectorUInt operator+(const VectorUInt& rhs) const;
    VectorUInt operator-(const VectorUInt& rhs) const;
    VectorUInt operator*(const VectorUInt& rhs) const;
    VectorUInt operator/(const VectorUInt& rhs) const;
    VectorUInt operator%(const VectorUInt& rhs) const;

    friend VectorUInt operator&(const VectorUInt& lhs, const VectorUInt& rhs);
    friend VectorUInt operator^(const VectorUInt& lhs, const VectorUInt& rhs);
    friend VectorUInt operator|(const VectorUInt& lhs, const VectorUInt& rhs);

    VectorUInt operator+(uint rhs) const;
    VectorUInt operator-(uint rhs) const;
    VectorUInt operator*(uint rhs) const;
    VectorUInt operator/(uint rhs) const;
    VectorUInt operator%(uint rhs) const;

    friend VectorUInt operator&(const VectorUInt& lhs, uint rhs);
    friend VectorUInt operator^(const VectorUInt& lhs, uint rhs);
    friend VectorUInt operator|(const VectorUInt& lhs, uint rhs);

    VectorUInt& operator=(const VectorUInt& rhs);
    VectorUInt& operator+=(const VectorUInt& rhs);
    VectorUInt& operator-=(const VectorUInt& rhs);
    VectorUInt& operator*=(const VectorUInt& rhs);
    VectorUInt& operator/=(const VectorUInt& rhs);
    VectorUInt& operator%=(const VectorUInt& rhs);

    VectorUInt& operator&=(const VectorUInt& rhs);
    VectorUInt& operator^=(const VectorUInt& rhs);
    VectorUInt& operator|=(const VectorUInt& rhs);

    VectorUInt& operator+=(uint rhs);
    VectorUInt& operator-=(uint rhs);
    VectorUInt& operator*=(uint rhs);
    VectorUInt& operator/=(uint rhs);
    VectorUInt& operator%=(uint rhs);

    VectorUInt& operator&=(uint rhs);
    VectorUInt& operator^=(uint rhs);
    VectorUInt& operator|=(uint rhs);

    friend std::ostream& operator<<(std::ostream& os, const VectorUInt& rhs);
    friend std::istream& operator>>(std::istream& is, VectorUInt& rhs);

    unsigned int& operator[](size_t index) const;

    friend bool operator==(const VectorUInt& lhs, const VectorUInt& rhs);
    friend bool operator!=(const VectorUInt& lhs, const VectorUInt& rhs);
    friend bool operator>(const VectorUInt& lhs, const VectorUInt& rhs);
    friend bool operator>=(const VectorUInt& lhs, const VectorUInt& rhs);
    friend bool operator<(const VectorUInt& lhs, const VectorUInt& rhs);
    friend bool operator<=(const VectorUInt& lhs, const VectorUInt& rhs);
};