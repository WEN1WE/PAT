/*
 * 1. 本题使用string ，代码会有开头结尾的特殊情况，使代码不简洁
 * 2. 本题使用 % / 更好
 */


#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int total = 0;
    int n, left, right, current, temp = 1;
    cin >> n;
    while (temp <= n) {
        right = n % temp;
        current = n / temp % 10;
        left = n / temp / 10;

        if (current == 0) {
            total += left * temp;
        } else if (current == 1) {
            total += left * temp + right + 1;
        } else {
            total += (left + 1) * temp;
        }
        temp *= 10;
    }
    cout << total;
    return 0;
}
