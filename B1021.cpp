/*
 * 1. char to int 强制类型转换是达不到要求的，char a = '0'; int i = int(a);// i = 48
 * 2。 char a = '9'; a - '0'; 可以帮忙实现功能
 * 3. for each 使用 auto 很方便
 */

#include <iostream>
using namespace std;

int main() {
    int result[1000] = {0};
    string s;
    cin >> s;

    for (auto e : s) {
        result[e - '0']++;
    }

    for (int i = 0; i < 1000; i++) {
        if (result[i]) {
            cout << i << ":" << result[i] << endl;
        }
    }
    return 0;
}
