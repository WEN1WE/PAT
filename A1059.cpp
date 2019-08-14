/*
 * 1. 素数表的建立
 * 2. 思考素数表到底建多大，可能有因式大于sqrt(n)，如最大值为6，建立的素数表只到2，但3也是因式：可能有唯一一个大于sqrt(n)的因式
 * 3. 考虑特殊情况1
 */

#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100010;

int main() {
    vector<bool> prime(MAX, true);
    for (int i = 2; i * i <= MAX; i++) {
        for (int j = 2; j * i <= MAX; j++) {
            prime[j * i] = false;
        }
    }

    bool flag1 = false;
    int n;
    scanf("%d", &n);
    printf("%d=", n);

    if (n == 1) {
        printf("1");
    }

    for (int i = 2; i < MAX; i++) {
        int count = 0, flag2 = false;
        while (prime[i] && n % i == 0) {
            count++;
            n /= i;
            flag2 = true;
        }
        if (flag2) {
            if (flag1) {
                printf("*");
            }
            printf("%d", i);
            flag1 = true;
        }

        if (count > 1) {
            printf("^%d", count);
        }

        if (n == 1) {
            break;
        }
    }

    if(n != 1) {  // 如果无法被sqrt(n)以内的质因子除尽
        printf("*%d", n);
    }

    return 0;
}
