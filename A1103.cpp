/*
 * 1. 本题的递归的写法很特别
 * 2. 对于递归程序要总体来看
 * 3. 就本题而言，每次递归后，tempResult是不会变的，所以最后一个元素，就是刚刚加入的
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> result;
vector<int> tempResult;
vector<int> power;

int maxSum = 0;
bool flag = false;

void dfs(int start, int leftN, int leftK, int factorSum) {
    if (leftN == 0 && leftK == 0) {
        flag = true;
        if (factorSum > maxSum) {
            result = tempResult;
            maxSum = factorSum;
        }
        return;
    }
    if (start < 1 || leftN <= 0 || leftK == 0) {
        return;
    }
    tempResult.push_back(start);
    dfs(start, leftN - power[start], leftK - 1, factorSum + start);
    tempResult.pop_back();
    dfs(start - 1, leftN, leftK, factorSum);
}

int main() {
    int n, k, p;
    scanf("%d %d %d", &n, &k, &p);
    power.push_back(-1);
    for (int i = 1; i <= n; i++) {
        int temp = pow(i, p);
        if (temp <= n) {
            power.push_back(temp);
        } else {
            break;
        }
    }
    
    dfs(power.size() - 1, n, k, 0);
    
    if (flag) {
        printf("%d = ", n);
        for (int i = 0; i < result.size(); i++) {
            if (i == 0) {
                printf("%d^%d", result[i], p);
            } else {
                printf(" + %d^%d", result[i], p);
            }
        }
    } else {
        printf("Impossible");
    }
    printf("\n");
    return 0;
}
