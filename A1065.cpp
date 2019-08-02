/*
 * 1. double：2^52 = 4503599627370496，一共16位，同理，double的精度为15~16位
 * 2. 出现溢出的时候，符号位会改变，特别是负溢出，符号位为0，可能值为0
 * 3. long long 的范围 -2^63 ~ 2^63 - 1
 * 4. long long 溢出时，真实值与表现的值之间相隔 2^64
 */

#include <iostream>
using namespace std;

bool compare(long long a, long long b, long long c) {
    long long sum = a + b;
    if (a > 0 && b > 0 && sum < 0) {
        return true;
    } else if (a < 0 && b < 0 && sum >= 0) {  //这里容易写成
        return false;
    } else {
        return sum > c;
    }
}

int main() {
    int n;
    long long a, b, c;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        if (compare(a, b, c)) {
            printf("Case #%d: true\n", i + 1);
        } else {
            printf("Case #%d: false\n", i + 1);
        }
    }
    return 0;
}
