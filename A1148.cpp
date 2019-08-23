/*
 * 1. 假设狼人，进行枚举
 */

#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> record;

bool reasonable(int liar1, int liar2, int werewolf1, int werewolf2) {
    for (int i = 1; i <= n; i++) {
        int said = record[i];
        if (i == liar1 || i == liar2) 
            said = -said;
        if (said < 0 && (-said != werewolf1 && -said != werewolf2)) {
            return false;
        } else if (said > 0 && (said == werewolf1 || said == werewolf2))
            return false;
        }
    return true;
}


int main() {
    scanf("%d", &n);
    record.resize(n + 1);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &record[i]);
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (k == i || k == j) {
                    continue;
                }
                if (reasonable(i, k, i, j)) {
                    printf("%d %d\n", i, j);
                    return 0;
                }
                if (reasonable(j, k, i, j)) {
                    printf("%d %d\n", i, j);
                    return 0;
                }
            }
        }
    }
    printf("No Solution\n");
    
    return 0;
}
