/*
 * 1. 模拟手写除法的过程
 */


#include <iostream>
using namespace std;

int main() {
    bool flag = false;
    int result[1000] = {0};
    int B, remainder = 0;
    string s;
    cin >> s >> B;

    for (int i = 0; i < s.length(); i++) {
        int A = remainder * 10 + s[i] - '0';
        result[i] = A / B;
        remainder = A % B;
    }

    for (int i = 0; i < s.length(); i++) {
        if (result[i] > 0) {
            flag = true;
        }
        if (flag) {
            cout << result[i];
        }
    }
    if (!flag) {
        cout << "0 " << remainder;
    } else {
        cout << " " << remainder;
    }
}
