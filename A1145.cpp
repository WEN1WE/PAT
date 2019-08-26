/*
 * 1. 二次探针法：公式，(a + step * step) % Tsize // 0 <= step < Tsize
 * 2. 对于查找的时候，0 <= step <= Tsize 为什么？
 */

#include <iostream>
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
    int MSize, N, M, total = 0;
    double avg = 0;
    scanf("%d %d %d", &MSize, &N, &M);
    
    while (!isPrime(MSize)) {
        MSize++;
    }
    vector<int> record(MSize);
    vector<bool> table(MSize);
    
    for (int i = 0; i < N; i++) {
        bool flag = false;
        int key, h;
        scanf("%d", &key);
        for (int step = 0; step < MSize; step++) {
            h = (key + step * step) % MSize;
            if (!table[h]) {
                table[h] = true;
                record[h] = key;
                flag = true;
                break;
            } 
        }
        if (!flag) {
            printf("%d cannot be inserted.\n", key);
        } 
    }
    
    for (int i = 0; i < M; i++) {
        int key, h;
        scanf("%d", &key);
        for (int step = 0; step <= MSize; step++) {
            h = (key + step * step) % MSize;
            total++;
            if ((record[h] == key && table[h]) || !table[h]) {
                break;
            }
        }
    }
    avg = total * 1.0 / M;
    printf("%.1f\n", avg);
    
    return 0;
}
