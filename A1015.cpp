/*
 * 1. 进制转换的时候，使用vector很方便
 * 2. 写成reverse()函数后就通过了，原因是先前循环时，值没有清零
 */

#include <iostream>
#include <algorithm>
#include <vector>
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

int reverse(int n, int radix) {
    int value = 0;
    vector<int> record;

    while (n != 0) {
        record.push_back(n % radix);
        n /= radix;
    }

    for (int i = 0; i < record.size(); i++) {
        value = value * radix + record[i];
    }
    return value;
}

int main() {
    int n, radix, value = 0;

    while (scanf("%d", &n) != EOF) {
        vector<int> record;
        if (n < 0) {
            break;
        }
        scanf("%d", &radix);
        value = reverse(n, radix);
        if (isPrime(n) && isPrime(value)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
