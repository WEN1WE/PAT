/*
 * 1. 开始的数字一定在 2-sqrt(n)之间
 * 2. 需要使用long long, 防止中间乘积越界
 * 3. 注意边界n 为 2 4 6 8
 * 4. 两层循环，使用两个计数器，这样代码清晰
 */

#include <iostream>
using namespace std;

int main() {
    long long n;
    scanf("%lld", &n);

    int start = 0, maxLen = 0;

    for (int i = 2; i * i <= n; i++) {
        int tempMax = 0;
        long long product = 1;

        for (int j = i; j <= n; j++) {
            product *= j;
            if (n % product != 0) {
                break;
            }
            tempMax++;
        }
        if (tempMax > maxLen) {
            maxLen = tempMax;
            start = i;
        }
    }

    if (maxLen == 0) {
        cout << 1 << endl;
        cout << n;
    } else {
        cout << maxLen << endl;
        for (long long i = start; i < maxLen + start; i++) {
            if (i != start) {
                cout << "*" << i;
            } else {
                cout << i;
            }
        }
    }
    return 0;
}
