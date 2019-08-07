/*
 * 1. 本题为贪心的问题，局部最优与全部最优的问题
 */

#include <iostream>
using namespace std;

int main() {
    int first = 0;
    int numberOfZero;
    int record[10];

    scanf("%d", &numberOfZero);

    for (int i = 1; i < 10; i++) {
        scanf("%d", &record[i]);
        if (first == 0 && record[i] > 0 ) {
            first = i;
            cout << i;
            record[i]--;
            for (int j = 0; j < numberOfZero; j++) {
                cout << 0;
            }
        }
        for (int j = 0; j < record[i]; j++) {
            cout << i;
        }
    }
    return 0;
}
