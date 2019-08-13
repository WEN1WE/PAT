/*
 * 1.  vector<bool> record(M, true);  // vector 初始化为 true
 * 2.  了解二次方探针法
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int M, N, key, position;
    scanf("%d %d", &M, &N);
    while (!isPrime(M)) {
        M++;
    }
    vector<bool> hashTable(M, false);

    for (int i = 0; i < N; i++) {
        if (i != 0) {
            printf(" ");
        }
        scanf("%d", &key);
        position = key % M;
        if (!hashTable[position]) {
            printf("%d", position);
            hashTable[position] = true;
        } else {
            int step;
            for (step = 1; step < M; step++) {
                position = (key + step * step) % M;
                if (!hashTable[position]) {
                    hashTable[position] = true;
                    printf("%d", position);
                    break;
                }
            }
            if (step >= M) {
                printf("-");
            }
        }
    }


    return 0;
}
