/*
 * int 范围
 * long long 范围
 * 如何取出一个正整数的每一位？
 */

#include <iostream>
using namespace std;

long long getNewN(long long n, long long d) {
    long long remainder;
    long long newN = 0;
    while (n != 0) {
        remainder = n % 10;
        if (remainder == d) {
            newN = newN * 10 + remainder;
        }
        n /= 10;
    }
    return newN;
}

int main() {
    long long n1, n2, d1, d2;
    cin >> n1 >> d1 >> n2 >> d2;
    cout << getNewN(n1, d1) + getNewN(n2, d2);
    return 0;
}
