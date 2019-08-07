/*
 * 1. 本题为贪心问题
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Mooncake {
    double amount;
    double totalPrice;
    double unitPrice;
};

bool cmp(Mooncake m1, Mooncake m2) {
    return m1.unitPrice > m2.unitPrice;
}

int main() {
    int N;
    double D;
    double maxProfit = 0;
    scanf("%d %lf", &N, &D);
    vector<Mooncake> moocakes(N);

    for (int i = 0; i < N; i++) {
        scanf("%lf", &moocakes[i].amount);
    }

    for (int i = 0; i < N; i++) {
        scanf("%lf", &moocakes[i].totalPrice);
    }

    for (int i = 0; i < N; i++) {
        moocakes[i].unitPrice = moocakes[i].totalPrice * 1.0 / moocakes[i].amount;
    }
    sort(moocakes.begin(), moocakes.end(), cmp);

    for (int i = 0; i < N; i++) {
        if (moocakes[i].amount <= D) {
            D -= moocakes[i].amount;
            maxProfit += moocakes[i].totalPrice;
        } else {
            maxProfit += D * moocakes[i].unitPrice;
            break;
        }
    }
    printf("%.2f", maxProfit);
    return 0;
}
