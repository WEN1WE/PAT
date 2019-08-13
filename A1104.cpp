/*
 * 1. 本题为数学问题，多写几步，观察特点
 */

#include <iostream>
using namespace std;

int main() {
    double value, result = 0;
    int n, index = 0;
    cin >> n;

    while (index < n) {
        cin >> value;
        result += (n - index) * value * (index + 1);
        index++;
    }

    printf("%.2f", result);
    return 0;
}
