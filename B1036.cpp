/*
 * 1. 把每一行先计算出来再打印，避免两重循环
 * 2. (n + 1) / 2, 实现了正整数的四舍五入
 */


#include <iostream>
using namespace std;

int main() {
    int n, row;
    string c;
    string end;
    string middle;
    cin >> n;
    cin >> c;

    row = (n + 1) / 2;  // 四舍五入

    for (int i = 0; i < n; i++) {
        end.append(c);
        if (i == 0 || i == n - 1) {
            middle.append(c);
        } else {
            middle.append(" ");
        }
    }

    for (int i = 0; i < row; i++) {
        if (i == 0 || i == row - 1) {
            cout << end << endl;
        } else {
            cout << middle << endl;
        }
    }
    return 0;
}
