#include "fraction.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Fraction::Fraction() : numerator(0), denominator(1) {}

ostream& operator<<(ostream& output, const Fraction& fract) {
    output << fract.numerator << '/' << fract.denominator;
    return output;
}

istream& operator>>(istream& input, Fraction& fract) {
    char slash;
    input >> fract.numerator >> slash >> fract.denominator;
    if (fract.denominator == 0) {
        cerr << "Invalid fraction with denominator 0" << endl;
        exit(1);
    }
    fract.reduce();
    return input;
}

const Fraction Fraction::operator+(const Fraction& rhs) const {
    Fraction result;
    result.numerator = numerator * rhs.denominator + rhs.numerator * denominator;
    result.denominator = denominator * rhs.denominator;
    result.reduce();
    return result;
}

const Fraction Fraction::operator-(const Fraction& rhs) const {
    Fraction result;
    result.numerator = numerator * rhs.denominator - rhs.numerator * denominator;
    result.denominator = denominator * rhs.denominator;
    result.reduce();
    return result;
}

const Fraction Fraction::operator*(const Fraction& rhs) const {
    Fraction result;
    result.numerator = numerator * rhs.numerator;
    result.denominator = denominator * rhs.denominator;
    result.reduce();
    return result;
}

const Fraction Fraction::operator/(const Fraction& rhs) const {
    Fraction result;
    result.numerator = numerator * rhs.denominator;
    result.denominator = denominator * rhs.numerator;
    if (result.denominator == 0) {
        cerr << "Division by zero" << endl;
        exit(1);
    }
    result.reduce();
    return result;
}

bool Fraction::operator==(const Fraction& rhs) const {
    return numerator == rhs.numerator && denominator == rhs.denominator;
}

int Fraction::getGCD(int num1, int num2) {
    int remainder = num2 % num1;
    if (remainder != 0)
        return getGCD(remainder, num1);
    return num1;
}

void Fraction::reduce() {
    int gcd = getGCD(abs(numerator), abs(denominator));
    numerator /= gcd;
    denominator /= gcd;

 
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}
