/*
 * 1. 此题与图的tour的方法类似，比较全部搜集的数据与应该得到的数据大小关系
 */

#include <iostream>
#include <map>
using namespace std;

int main() {
    int K, N;
    scanf("%d", &K);
    
    for (int i = 0; i < K; i++) {
        scanf("%d", &N);
        map<int, bool> checkRow;
        map<int, bool> checkDiagonal1;
        map<int, bool> checkDiagonal2;
        for (int x = 1; x <= N; x++) {
            int y;
            scanf("%d", &y);
            checkRow[y] = true;
            checkDiagonal1[y - x] = true;
            checkDiagonal2[y + x] = true;
        }
        if (checkRow.size() != N || checkDiagonal1.size() != N || checkDiagonal2.size() != N) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
    return 0;
}
