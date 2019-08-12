/*
 * 1. 当第二行为空的时候，要输出一个换行符
 * 2. 本题采用的是先收集，再计算的思想
 */

#include <iostream>
#include <vector>
using namespace std;

const int MAXLENGTH = 100010;
const int MAX = 1000000010;

int main() {
    int n, maxNumber = 0, minNumber = MAX, count = 0;
    int leftMax[MAXLENGTH];
    int rightMin[MAXLENGTH];
    int numbers[MAXLENGTH];
    vector<int> collect;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            leftMax[0] = numbers[0];
        } else {
            leftMax[i] = max(leftMax[i - 1], numbers[i]);
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            rightMin[i] = numbers[i];
        } else {
            rightMin[i] = min(rightMin[i + 1], numbers[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (leftMax[i] <= numbers[i] && numbers[i] <= rightMin[i]) {
            count++;
            collect.push_back(numbers[i]);
        }
    }

    cout << count << endl;
    if (count == 0) {
        cout << endl;
    }

    for (int i = 0; i < collect.size(); i++) {
        if (i != 0) {
            cout << " ";
        }
        cout << collect[i];
    }

    return 0;
}
