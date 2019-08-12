/*
 * 1. long int 范围就是int
 * 2. 使用vector 超内存
 */

#include <iostream>
using namespace std;

const int INF = 0x7fffffff;
const int maxLength = 200010;
int main() {
    int n1, n2, median, p = 0, value = 0, count = 0, count1 = 1;
    scanf("%d", &n1);
    int sequence[maxLength];
    sequence[n1] = INF;
    for (int i = 0; i < n1; i++) {
        scanf("%d", &sequence[i]);
    }
    scanf("%d", &n2);
    median = (n1 + n2 - 1) / 2;

    bool flag = false;
    scanf("%d", &value);
    while (count < median) {
        while (sequence[p] < value && count < median) {
            flag = true;
            p++;
            count++;
        }
        if (!flag && count < median) {
            if (count1 < n2) {
                scanf("%d", &value);
                count1++;
            } else {
                value = INF;
            }
            count++;
        }
        flag = false;
    }
    printf("%d", min(value, sequence[p]));
    return 0;
}
