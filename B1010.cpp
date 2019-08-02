/*
 * 1. 如何判断输入已经结束？cin >> 如果没有输入，会返回false
 * 2. 要保证结束的时候末尾没有空格，可以 （第一项） （空格 第二项） （空格 第三项）这样输出
 * 3. 边界：当没有非零输出时， 输出'0 0'
 */


#include <iostream>
using namespace std;

int main() {
    int coefficient, exponent, flag = 0;

    while (cin >> coefficient >> exponent) {
        if (exponent > 0) {
            if (flag != 0) {
                cout << " ";
            }
            cout << coefficient * exponent << " " << exponent - 1;
            flag = 1;
        }
    }

    if (flag == 0) {
        cout << "0 0";
    }
}
