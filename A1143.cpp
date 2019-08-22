/*
 * 1. 本程序建树超时
 * 2. 本题也可以建树，但是不要插入建树，使用前序和中序建树
 * 3. 观察题目特点，发现第一个能区分u, v的就是所求
 * 4. findLowest 里面的等号特别关键，要把根节点自己也算在内
 */
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int findLowest(vector<int> & preorder, int u, int v) {
    int greater = max(u, v);
    int smaller = min(u, v);
    for (int i = 0; i < preorder.size(); i++) {
        if (preorder[i] >= smaller && preorder[i] <= greater) {
            return preorder[i];
        }
    }
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    vector<int> preorder(n);
    map<int, bool> mp;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
        mp[preorder[i]] = true;
    }
    
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        int flag1 = mp.find(u) == mp.end();
        int flag2 = mp.find(v) == mp.end();
        
        if (flag1 && flag2) {
            printf("ERROR: %d and %d are not found.", u, v);
        } else if (flag1) {
            printf("ERROR: %d is not found.", u);
        } else if (flag2) {
            printf("ERROR: %d is not found.", v);
        } else {
            int lowest = findLowest(preorder, u, v);
            if (u == lowest) {
                printf("%d is an ancestor of %d.", u, v);
            } else if (v == lowest) {
                printf("%d is an ancestor of %d.", v, u);
            } else {
                printf("LCA of %d and %d is %d.", u, v, lowest);
            }
        }
        printf("\n");
    }
    return 0;
}
