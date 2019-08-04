/*
 * 1. 本题主要使用% /，划分两段输出
 */


#include <iostream>
using namespace std;

int main() {
    bool flag = false;
    int a, b, n1, n2;
    string sum;
    cin >> a >> b;

    sum = to_string(a + b);
    if (sum[0] == '-') {
        cout << '-';
        sum = sum.substr(1);
    }

    n1 = sum.length() % 3;
    n2 = sum.length() / 3;

    if (n1 != 0) {
        flag = true;
    }
    cout << sum.substr(0, n1);
    for (int i = 0; i < n2; i++) {
        if (flag) {
            cout << ",";
        }
        flag = true;
        cout << sum.substr(n1 + 3 * i, 3);
    }
    return 0;
}
