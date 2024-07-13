#pragma once
#include <iostream>

#ifndef FRACTION_H
#define FRACTION_H

class Fraction {
private:
    int numerator;
    int denominator;
    int getGCD(int num1, int num2);

public:
    // Default constructor
    Fraction();

    // Overloaded stream operators
    friend std::ostream& operator<< (std::ostream& output, const Fraction& fract);
    friend std::istream& operator>> (std::istream& input, Fraction& fract);

    // Overloaded arithmetic operators
    const Fraction operator+(const Fraction& rhs) const;
    const Fraction operator-(const Fraction& rhs) const;
    const Fraction operator*(const Fraction& rhs) const;
    const Fraction operator/(const Fraction& rhs) const;

    // Overloaded comparison operator
    bool operator==(const Fraction& rhs) const;

    // Reduce/simplify a fraction
    void reduce();
};

#endif // !FRACTION_H