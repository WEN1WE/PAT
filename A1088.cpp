/*
 * 1. 此题与A1081类似
 * 2. 不要在有理数的结构体里面加interger, 不然代码会很复杂
 */
#include <iostream>
#include <cmath>
using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

struct Rational {
    long long numerator = 0;
    long long denominator = 1;
};

void simplify(Rational & r) {
    long long g;
    if (r.denominator < 0) {
        r.denominator = -r.denominator;
        r.numerator = -r.numerator;
    }

    g = gcd(abs(r.denominator), abs(r.numerator));
    r.denominator /= g;
    r.numerator /= g;
}

Rational add(Rational & r1, Rational & r2) {
    Rational result;
    long long g;
    result.numerator = r1.numerator * r2.denominator + r1.denominator * r2.numerator;
    result.denominator = r1.denominator * r2.denominator;
    simplify(result);
    return result;
}

Rational subtract(Rational & r1, Rational & r2) {
    Rational result;
    long long g;
    result.numerator = r1.numerator * r2.denominator - r1.denominator * r2.numerator;
    result.denominator = r1.denominator * r2.denominator;
    simplify(result);
    return result;
}

Rational multiply(Rational & r1, Rational & r2) {
    Rational result;
    long long g;
    result.numerator = r1.numerator * r2.numerator;
    result.denominator = r1.denominator * r2.denominator;
    simplify(result);
    return result;
}

Rational divide(Rational & r1, Rational & r2) {
    Rational result;
    long long g;
    result.numerator = r1.numerator * r2.denominator;
    result.denominator = r1.denominator * r2.numerator;
    if (result.denominator != 0) {
        simplify(result);
    }
    return result;
}

void printRational(Rational & r) {
    long long temp = r.numerator;
    if (r.denominator == 0) {
        printf("Inf");
        return;
    }
    if (temp < 0) {
        printf("(");
    }
    if (r.denominator == 1) {
        printf("%lld", r.numerator);
    } else if (abs(r.numerator) > abs(r.denominator)) {
        printf("%lld %lld/%lld", r.numerator / r.denominator, abs(r.numerator) % r.denominator, r.denominator);
    } else {
        printf("%lld/%lld", r.numerator, r.denominator);
    }
    if (temp < 0) {
        printf(")");
    }
}

void print(Rational & r1, Rational & r2, Rational & result, char symbol) {
    printRational(r1);
    printf(" %c ", symbol);
    printRational(r2);
    printf(" = ");
    printRational(result);
    printf("\n");
}

int main() {
    Rational r1, r2, sum, difference, product, quotient;
    scanf("%lld/%lld %lld/%lld", &r1.numerator, &r1.denominator, &r2.numerator, &r2.denominator);
    simplify(r1);
    simplify(r2);
    sum = add(r1, r2);
    difference = subtract(r1, r2);
    product = multiply(r1, r2);
    quotient = divide(r1, r2);
    print(r1, r2, sum, '+');
    print(r1, r2, difference, '-');
    print(r1, r2, product, '*');
    print(r1, r2, quotient, '/');
    return 0;
}

