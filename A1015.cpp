/*
 * 1. 进制转换的时候，使用vector很方便
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

int main() {
    int n, radix, value = 0;

    while (scanf("%d", &n) != EOF) {
        vector<int> record;
        if (n < 0) {
            break;
        }
        scanf("%d", &radix);

        if (!isPrime(n)) {
            printf("No\n");
            return 0;
        }

        while (n != 0) {
            record.push_back(n % radix);
            n /= radix;
        }

        for (int e : record) {
            value = value * radix +  e;
        }

        if (isPrime(value)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
