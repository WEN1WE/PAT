/*
 * 1. 每次循环玩，要将某些数据清0，例如本题中的sum
 * 2. 从测试来看，并没有要求检查是否为数字
 */

#include <iostream>
using namespace std;

int main() {
    int n;
    string s;
    bool sign = true;
    int sum = 0, z;
    int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    char table[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < 17; j++) {
            sum += (s[j] - '0') * weight[j];
        }
        z = sum % 11;
        if (table[z] != s[17]) {
            sign = false;
            cout << s << endl;
        }
        sum = 0;
    }
    if (sign) {
        cout << "All passed";
    }
    return 0;
}
