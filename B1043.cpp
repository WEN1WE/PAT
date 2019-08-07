/*
 * 1. 此题使用 hash table 简单
 */

#include <iostream>
using namespace std;

int main() {
    int count[256] = {0};
    string table = "PATest";
    string s;
    cin >> s;

    for (auto e : s) {
        count[e]++;
    }

    while (true) {
        bool flag = false;
        for (int i = 0; i < 6; i++) {
            if (count[table[i]]) {
                count[table[i]]--;
                flag = true;
                cout << table[i];
            }
        }
        if (!flag)  {
            break;
        }
    }
    return 0;
}
