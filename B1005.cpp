/*
 * 1. hash table 用得很巧妙，就是用实验得到得结果作为下标，进行标记
 */


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void helper(int n, bool hashTable[]) {
    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
            hashTable[n] = true;
        } else {
            n = (3 * n + 1) / 2;
            hashTable[n] = true;
        }
    }
}

bool cmp(int n, int m) {
    return n > m;
}

int main() {
    int n;
    bool hashTable[1000] = {false};
    cin >> n;
    int numbers[n];
    vector<int> result;

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        helper(numbers[i], hashTable);
    }

    for (int i = 0; i < n; i++) {
        if (!hashTable[numbers[i]]) {
            result.push_back(numbers[i]);
        }
    }
    sort(result.begin(), result.end(), cmp);

    for (int i = 0; i < result.size(); i++) {
        if (i != 0) {
            cout << " ";
        }
        cout << result[i];
    }
    return 0;
}
