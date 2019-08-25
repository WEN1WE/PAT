/*
 * 1. 每次顺时针读完，都要缩小边界
 * 2. 所有的N，都要使用完
 * 3. (int)ceil(sqrt(N * 1.0)); // 向上取整 floor 向下取整
 * 4. 边界，当n为1的时候
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool cmp(int n1, int n2) {
    return n1 > n2;
}

int main() {
    int N, row, column;
    scanf("%d", &N);
    vector<int> values(N);
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &values[i]);
    }
    if (N == 1) {
        printf("%d", values[0]);
        return 0;
    }
    
    sort(values.begin(), values.end(), cmp);
    
    row = (int)ceil(sqrt(N * 1.0));
    while (N % row != 0) {
        row++;
    }
    column = N / row;
    
    vector<vector<int>> matrix(row);
    for (auto & e : matrix) {
        e.resize(column);
    }
    
    int current = 0, curRow = 0, curCol = 0;
    int up = 0, down = row, left = 0, right = column;
    
    while (current < N) {
        while (current < N && curCol < right - 1) {
            matrix[curRow][curCol++] = values[current++];
        }
        while (current < N && curRow < down - 1) {
            matrix[curRow++][curCol] = values[current++];
        }
        while (current < N && curCol > left) {
            matrix[curRow][curCol--] = values[current++];
        }
        while(current < N && curRow > up) {
            matrix[curRow--][curCol] = values[current++];
        }
        up++;
        down--;
        left++;
        right--;
        curCol++;
        curRow++;
        
        if (current == N - 1) {
            matrix[curRow][curCol] = values[current++];
        }
    }
    for (int i = 0; i < row; i++) {
        
        for (int j = 0; j < column; j++) {
            if (j != 0) {
                printf(" ");
            }
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
