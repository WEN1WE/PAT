/*
 * 1. 此题主要在于把有用的信息记录下来
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<char> result(3);
    double oddW, oddT, oddL;
    double profit = 1;
    for (int i = 0; i < 3; i++) {
        cin >> oddW >> oddT >> oddL;
        if (oddW > oddT && oddW > oddL) {
            profit *= oddW;
            result[i] = 'W';
        } else if (oddT > oddW && oddT > oddL) {
            profit *= oddT;
            result[i] = 'T';
        } else {
            profit *= oddL;
            result[i] = 'L';
        }
    }
    profit = (profit * 0.65 - 1) * 2;

    printf("%c %c %c %.2f", result[0], result[1], result[2], profit);
    return 0;
}
