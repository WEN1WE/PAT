/*
 * 1. 本题使用hash table简单
 */

#include <iostream>
using namespace std;

int main() {
    bool hashTable[256] = {false};
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    for (auto e : s2) {
        hashTable[e] = true;
    }

    for (auto e : s1) {
        if (!hashTable[e]) {
            cout << e;
        }
    }
    return 0;
}
