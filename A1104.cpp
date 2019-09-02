/*
 * 1. 本题为数学问题，多写几步，观察特点
 */

#include <iostream>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    double total = 0;
    
    for (int i = 1; i <= N; i++) {
        double value;
        scanf("%lf", &value);
        total += value * i * (N + 1 - i);
    }
    
    printf("%.2f", total);
    return 0;
}
