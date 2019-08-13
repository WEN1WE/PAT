/*
 * 1. 本题最大公约数的写法很简单
 * 2. abs 函数 在<cmath> 中
 * 3. 最大公约数是对绝对值求的，不然分子分母符号会交换
 * 4. print的时候注意分子为0
 */

#include <iostream>
#include <cmath>
using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

struct Rational {
    long long numerator;
    long long denominator;
};

void add(Rational & r1, Rational & r2) {
    long long g;
    r1.numerator = r1.denominator * r2.numerator + r1.numerator * r2.denominator;
    r1.denominator = r1.denominator * r2.denominator;
    g = gcd(abs(r1.denominator), abs(r1.numerator));
    r1.numerator /= g;
    r1.denominator /= g;
}

void print(Rational r) {
    if (r.denominator == 1) {
        printf("%lld\n", r.numerator);
    } else if (abs(r.numerator) > r.denominator) {
        printf("%lld %lld/%lld\n", r.numerator / r.denominator, abs(r.numerator) % r.denominator, r.denominator);
    } else {
        printf("%lld/%lld\n", r.numerator, r.denominator);
    }
}

int main() {
    int n;
    Rational sum, temp;
    sum.denominator = 1;
    sum.numerator = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%lld/%lld", &temp.numerator, &temp.denominator);
        add(sum, temp);
    }

    print(sum);
    return 0;
}

