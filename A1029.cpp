/*
 * 1. long int 范围就是int
 * 2. 使用vector 超内存
 * 3. 由于超时，所以只能保持第一个序列
 * 4. 在原超时的代码上改
 * 5. p1, p2的位置其实是指向的下一个，所以改的代码也要注意这一点
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


/*
 * 1. long int 范围就是int
 * 2. 使用vector 超内存
 */

#include <iostream>
using namespace std;

const int INF = 0x7fffffff;
const int maxLength = 200010;
int main() {
    int n1, n2, median, p1 = 0, p2 = 0, count = 0;
    scanf("%d", &n1);
    int sequence1[maxLength];
    sequence1[n1] = INF;
    for (int i = 0; i < n1; i++) {
        scanf("%d", &sequence1[i]);
    }
    scanf("%d", &n2);
    int sequence2[maxLength];
    for (int i = 0; i < n2; i++) {
        scanf("%d", &sequence2[i]);
    }
    sequence2[n2] = INF;
    median = (n1 + n2 - 1) / 2;

    while (count < median) {
        if (sequence1[p1] < sequence2[p2]) {
            p1++;
        } else {
            p2++;
        }
        count++;
    }

    printf("%d", min(sequence1[p1], sequence2[p2]));
    return 0;
}
