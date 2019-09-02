/*
 * 1. 每次顺时针读完，都要缩小边界
 * 2. 所有的N，都要使用完
 * 3. (int)ceil(sqrt(N * 1.0)); // 向上取整 floor 向下取整
 * 4. 边界，当n为1的时候
 * 5. 本程序最大的问题就是没法很好处理中间最好剩下的一个
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool cmp(int x, int y) {
    return x > y;
}

int main() {
    int N, m, n;
    scanf("%d", &N);
    vector<int> record(N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &record[i]);
    }
    sort(record.begin(), record.end(), cmp);

    if (N == 1) {
        printf("%d", record[0]);
        return 0;
    }
    
    m = int(ceil(sqrt(N)));
    while (true) {
        if (N % m == 0) {
            break;
        } else {
            m++;
        }
    }
    n = N / m;
    vector<vector<int>> matrix(m);
    for (auto & e : matrix) {
        e.resize(n);
    }
    int cnt = 0;
    int left = 0, right = n - 1, up = 0, down = m - 1;
    
    while (cnt < N) {
        for (int i = left; cnt < N && i < right; i++) {
            matrix[up][i] = record[cnt++];
        }
        for (int i = up; cnt < N && i < down; i++) {
            matrix[i][right] = record[cnt++];
        }
        for (int i = right; cnt < N && i > left; i--) {
            matrix[down][i] = record[cnt++];
        }
        for (int i = down; cnt <= N - 1 && i > up; i--) {
            matrix[i][left] = record[cnt++];
        }
        
        left++;
        right--;
        up++;
        down--;
        if (cnt == N - 1) {
            matrix[up][left] = record[cnt++];
        }
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j != 0) {
                printf(" ");
            }
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
