/*
 * 1. 使用% / 取出数字的每一位
 */

#include <iostream>
using namespace std;

int main() {
    int a = 0, b = 0, c = 0, n;
    cin >> n;
    a = n % 10;
    n = n / 10;
    b = n % 10;
    c = n / 10;
    //cout << a << " " << b << " " << c;
    for (int i = 0; i < c; i++) {
        cout << 'B';
    }

    for (int i = 0; i < b; i++) {
        cout << 'S';
    }

    for (int i = 1; i <= a; i++) {
        cout << i;
    }
    return 0;
}
