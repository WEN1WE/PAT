/*
 * 1. 使用hash table 的思想，本题就简单
 */

#include <iostream>
using namespace std;

int main() {
    int bead[256] = {0};
    int lack = 0;
    string s1, s2;
    cin >> s1 >> s2;

    for (auto e : s1) {
        bead[e]++;
    }
    for (auto e : s2) {
        if (bead[e] > 0) {
            bead[e]--;
        } else {
            lack++;
        }
    }

    if (!lack) {
        cout << "Yes" << " " << s1.length() - s2.length();
    } else {
        cout << "No" << " " << lack;
    }
    return 0;
}
