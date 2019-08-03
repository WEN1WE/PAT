/*
 * 1. 用sign可以使结尾确定空格
 * 2. 注意边界，虽然这题没有
 */

#include <iostream>
using namespace std;

int main() {
    bool sign1 = true, sign2 = false;
    int n, b, count = 0;
    int result[32];
    cin >> n >> b;

    while (n != 0) {
        result[count++] = n % b;
        n = n / b;
    }

    for (int i = 0; i <= count / 2 - 1; i++) {
        if (result[i] != result[count - i - 1]) {
            sign1 = false;
            break;
        }
    }

    if (sign1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    while (count != 0) {
        if (sign2) {
            cout << " ";
        }
        cout << result[--count];
        sign2 = true;
    }
    return 0;
}
