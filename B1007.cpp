/*
 * 1. 判断素数的写法
 * 2. 除2以外，素数都是奇数
 */

#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, count = 0;
    cin >> n;
    for (int i = 5; i <= n; i += 2) {
        if (isPrime(i) && isPrime(i - 2)) {
            count++;
        }
    }
    cout << count;
}
