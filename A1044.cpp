/*
 * 1. map的key不能使用结构体
 * 2. 本题容易超时
 * 3. 放入vector的东西，有自己的一份拷贝
 * 4. 本题使用map效率太低
 * 5. 本题的一个坑在于minCost 的取值
 * 6. 本题传值要传引用才不会超时,由于传入vector<int>， 函数生成自己的一份拷贝
 */

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(int left, int right, int M, vector<int> & total) {
    int mid;
    int start = left;
    while (left < right) {
        mid = (left + right) / 2;
        if (total[mid] - total[start - 1] >= M) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

struct Pair {
    int left;
    int right;
} tempPair;

int main() {
    int N, M, minCost = 100000010;
    scanf("%d %d", &N, &M);
    vector<int> total(N + 1);
    vector<Pair> pairs;

    for (int i = 1; i < N + 1; i++) {
        scanf("%d", &total[i]);
        total[i] += total[i - 1];
    }

    for (int i = 1; i < N + 1; i++) {
        int d;
        tempPair.left = i;
        tempPair.right = binarySearch(i, N, M, total);
        d = total[tempPair.right] - total[i - 1];
        if (d >= M) {
            if (d == minCost) {
                pairs.push_back(tempPair);
            } else if (d < minCost) {
                minCost = d;
                pairs.clear();
                pairs.push_back(tempPair);
            }
        }
    }

    for (auto e : pairs) {
        printf("%d-%d\n", e.left, e.right);
    }
    return 0;
}
