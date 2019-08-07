/*
 * 1. 使用hash table, 本题简单
 * 2. scanf 比 cin 快很多
 */

#include <iostream>
using namespace std;

int main() {
    bool flag = false;
    int hashTable[10001] = {0};
    int n;
    cin >> n;
    int numbers[n];

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        hashTable[numbers[i]]++;
    }

    for (int i = 0; i < n; i++) {
        if (hashTable[numbers[i]] == 1) {
            flag = true;
            cout << numbers[i];
            break;
        }
    }

    if (!flag) {
        cout << "None";
    }
    return 0;
}
