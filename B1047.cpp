/*
 * 1. 本题使用hash table 简单
 */

#include <iostream>
using namespace std;

int main() {
    int n;
    int totalScore[1001] = {0};
    int maxID = 0;
    int maxScore = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int id, temp, score;
        scanf("%d-%d %d", &id, &temp, &score);
        totalScore[id] += score;
        if (maxScore < totalScore[id]) {
            maxScore = totalScore[id];
            maxID = id;
        }
    }

    cout << maxID << " " << maxScore;
}
