/*
 * 1. 本题为数学问题
 * 2. 使用变量存下当前楼层，代码更加简化
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, total = 0;
    cin >> n;
    vector<int> requests(n + 1);
    total += 5 * n;
    requests[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> requests[i];
    }

    for (int i = 1; i <= n; i++) {
        int temp = requests[i] - requests[i - 1];
        total += temp > 0 ? 6 * temp : 4 * (-temp);
    }
    cout << total;
}
