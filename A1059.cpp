/*
 * 1. 素数表的建立
 * 2. 思考素数表到底建多大，可能有因式大于sqrt(n)，如最大值为6，建立的素数表只到2，但3也是因式：可能有唯一一个大于sqrt(n)的因式
 * 3. 考虑特殊情况1
 */

#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100010;

int main() {
    vector<bool> table(MAX, true);

    for (int i = 2; i * i <= MAX; i++) {
        for (int j = 2; j * j <= MAX; j++) {
            table[i * j] = false;
        }
    }
    long long N;
    cin >> N;

    if (N == 1) {
        cout << "1=1" << endl;
        return 0;
    } else {
        cout<< N << "=";
    }

    bool flag = false;
    for (int i = 2; i <= MAX; i++) {
        int cnt = 0;
        while (table[i] && N % i == 0) {
            cnt++;
            N = N / i;
        }
        if (flag && cnt > 0) {
            cout << "*";
        }
        if (cnt > 0) {
            cout << i;
            flag = true;
        }
        if (cnt > 1) {
            cout << "^" << cnt;
        }
        if (N == 1) {
            break;
        }
    }
    return 0;
}
