/*
 * 1. 统计类型的题，hash table 比较方便
 */

#include <iostream>
using namespace std;

int main() {
    string s;
    int maxCount = 0;
    int count[256] = {0};
    getline(cin, s);

    for (auto e : s) {
        if (isalpha(e)) {
            count[tolower(e)]++;
            if (count[tolower(e)] > maxCount) {
                maxCount = count[tolower(e)];
            }
        }
    }
    for (int i = 0; i < 256; i++) {
        if (count[i] == maxCount) {
            cout << char(i) << " ";
            break;
        }
    }
    cout << maxCount;
    return 0;
}
