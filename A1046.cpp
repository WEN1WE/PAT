/*
 * 1. 本题的优化解法是将距离开始点的距离先计算出来，再相减
 * 2. 利用环上顺时针走，和逆时针走的距离和为定值
 */

#include <iostream>
using namespace std;

int main() {
    int n, m, clockwise = 0, total = 0;
    int exit1, exit2;
    cin >> n;
    int distances[n];
    distances[0] = 0;

    for (int i = 0; i < n; i++) {
        cin >> distances[i + 1];
        total += distances[i + 1];
        distances[i + 1] += distances[i];
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> exit1 >> exit2;
        if (exit1 > exit2) {
            swap(exit1, exit2);
        }
        clockwise = distances[exit2 - 1] - distances[exit1 - 1];
        cout << min(total - clockwise, clockwise) << endl;
    }
    return 0;
}

/*
#include <iostream>
using namespace std;

int main() {
    int n, m, clockwiseDistance = 0, total = 0;
    int exit1, exit2;
    cin >> n;
    int distances[n];

    for (int i = 0; i < n; i++) {
        cin >> distances[i];
        total += distances[i];
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> exit1 >> exit2;
        if (exit1 > exit2) {
            swap(exit1, exit2);
        }
        while (exit1 != exit2) {
            clockwiseDistance += distances[exit1 - 1];
            exit1++;
        }
        cout << min(total - clockwiseDistance, clockwiseDistance) << endl;
        clockwiseDistance = 0;
    }
    return 0;
}
 */
