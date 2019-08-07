/*
 * 1. 数组int a[10] = {1};只初始化的第一个元素
 * 2. 测试点2不过的原因是：第一行字符串可能为空，要使用getline
 *
 */

#include <iostream>
using namespace std;

int main() {
    bool hashTable[256] = {false};
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    for (auto e : s1) {
        hashTable[toupper(e)] = true;
        hashTable[tolower(e)] = true;
        if (e == '+') {
            for (int i = 'A'; i  <= 'Z'; i++) {
                hashTable[i] = true;
            }
        }
    }

    for (auto e : s2) {
        if (!hashTable[e]) {
            cout << e;
        }
    }
    return 0;
}
