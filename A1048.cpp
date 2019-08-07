/*
 * 1. 要注意，虽然硬币值只有500， 但hashTable 要建1000，防止越界
 * 2. 程序先一定要走几步
 */

#include <iostream>
using namespace std;

int main() {
    int N, M, value;
    int hashTable[1005] = {0};
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%d", &value);
        hashTable[value]++;
    }

    for (int i = 1; i <= M / 2; i++) {
        if (--hashTable[i] >= 0 && --hashTable[M - i] >= 0) {
            printf("%d %d", i, M - i);
            return 0;
        }
    }
    printf("No Solution");
    return 0;
}
