/*
 * 学会如何处理结尾不能有多余空格
 * 用 p 指向移动后的数组的第一个元素，这样更加简单
 * C++ 创建数组 int A[100];
 */


#include <iostream>
using namespace std;

int main() {
    int n, m, p;  // p 指向移动后的数组的第一个元素
    cin >> n >> m;
    int a[n];

    m = m % n; // n = 6, m = 6 或 12，相当于没有动
    p = n - m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++, p++) {
        cout << a[p % n];
        if (i != n - 1) {
            cout << " ";
        }
    }
    return 0;
}
