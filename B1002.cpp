/*
 * 1. 用sign解决末尾没有空格的问题
 * 2. '1' - '0' 实现 char to int
 */

#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    bool sign = false;
    string s;
    string sumS;
    string table[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

    cin >> s;
    for (auto e : s) {
        sum += e - '0';
    }

    sumS = to_string(sum);

    for (auto e : sumS) {
        if (sign) {
            cout << " ";
        }
        cout << table[e - '0'];
        sign = true;
    }
    return 0;
}
