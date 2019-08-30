/*
 * 1. 注意，一个物品可与很对不相融
 * 2. 观察题目中哪个变量最小
 * 3. 跳出二重循环
 */

#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int MAX = 100000;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    vector<int> table[MAX];
    bool isThere[MAX];
    
    for (int i = 0; i < N; i++) {
        int goods1, goods2;
        scanf("%d %d", &goods1, &goods2);
        table[goods1].push_back(goods2);
        table[goods2].push_back(goods1);
    }
    
    for (int i = 0; i < M; i++) {
        fill(isThere, isThere + MAX, false);
        int K;
        bool flag = true;
        scanf("%d", &K);
        vector<int> record(K);
        for (int j = 0; j < K; j++) {
            scanf("%d", &record[j]);
            isThere[record[j]] = true;
        }
        
        for (auto e1 : record) {
            for (auto e2 : table[e1]) {
                if (isThere[e2]) {
                    printf("No\n");
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                break;
            }
        }
        if (flag) {
            printf("Yes\n");
        }
    }
    
    return 0;
}
