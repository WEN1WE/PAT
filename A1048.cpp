/*
 * 1. 要注意，虽然硬币值只有500， 但hashTable 要建1000，防止越界
 * 2. 程序先一定要走几步
 * 3. 本题也可以使用二分查找，但是扣了1分
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


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    bool flag = false;
    int N, M;
    scanf("%d %d", &N, &M);
    vector<int> values(N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &values[i]);
    }

    sort(values.begin(), values.end());

    for (int i = 0; i < N; i++) {
        int j = upper_bound(values.begin(), values.end(), M - values[i]) - values.begin();
        if (i != (j - 1) && values[i] + values[j - 1] == M) {
            flag = true;
            cout << values[i] << " " << values[j - 1];
            break;
        }
    }
    if (!flag) {
        cout << "No Solution";
    }
}
