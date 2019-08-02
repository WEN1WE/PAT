/*
 * 1. 用数组的小标来标记一些信息，会使代码简化，但空间浪费了
 * 2. 保证末尾没有空格，还是一个搭配的问题 （K) (空格 指数 空格 系数）
 */


#include <iostream>
#include <vector>
using namespace std;

int main() {
    int k1, k2, exponent, count = 0;
    double coefficient;
    vector<double> record(1001);

    cin >> k1;
    for (int i = 0; i < k1; i++) {
        cin >> exponent >> coefficient;
        record[exponent] += coefficient;
    }

    cin >> k2;
    for (int i = 0; i < k2; i++) {
        cin >> exponent >> coefficient;
        record[exponent] += coefficient;
    }

    for (double coeff : record) {
        if (coeff != 0) {
            count++;
        }
    }

    cout << count;
    for (int i = 1000; i >= 0; i--) {
        if (record[i] != 0) {
            printf(" %d %.1f", i, record[i]);
        }
    }
    return 0;
}
