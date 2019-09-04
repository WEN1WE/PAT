/*
 * 1. 只用输入第一个，所以递归就可以
 * 2. 本程序也提供了一种不用生成树，就能转化输出树的方法
 * 3. 关闭同步，ios::sync_with_stdio(false),但程序好像也没有变快
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> preorder;
vector<int> inorder;

int find(int preL, int preR, int inL, int inR) {
    if (preL == preR) {
        return preorder[preL];
    }
    int root = preorder[preL];
    for (int i = inL; i <= inR; i++) {
        if (inorder[i] == root) {
            int len = i - inL;
            if (len != 0) {
                return find(preL + 1, preL + len, inL, i - 1);
            } else {
                return find(preL + len + 1, preR, i + 1, inR);
            }
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    preorder.resize(N);
    inorder.resize(N);
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &preorder[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &inorder[i]);
    }
    cout << find(0, N - 1, 0, N - 1) << endl;
    return 0;
}
