/*
 * 1. 使用i != 0 可以解决末尾没有空格的问题
 * 2. 由于分数最大为100，所以数组要开101
 */

#include <iostream>
using namespace std;

int main() {
    int count[101] = {0};
    int n, k, score;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> score;
        count[score]++;
    }
    cin >> k;

    for (int i = 0; i < k; i++) {
        cin >> score;
        if (i != 0) {
            cout << " ";
        }
        cout << count[score];
    }

    return 0;
}
