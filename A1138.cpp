/*
 * 1. 只用输入第一个，所以递归就可以
 * 2. 本程序也提供了一种不用生成树，就能转化输出树的方法
 * 3. 关闭同步，ios::sync_with_stdio(false),但程序好像也没有变快
 */

#include <iostream>
#include <vector>
using namespace std;

int getFirst(vector<int> & preorder, vector<int> & inorder, int preL, int preR, int inL, int inR) {
    if (preL == preR) {
        return preorder[preL];
    }
    int root = preorder[preL];
    for (int i = inL; i <= inR; i++) {
        if (inorder[i] == root) {
            if (i == inL) {
                return getFirst(preorder, inorder, preL + 1, preR, inL + 1, inR);
            } else {
                int len = i - inL;
                return getFirst(preorder, inorder, preL + 1, preL + len, inL, i - 1);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> preorder(n);
    vector<int> inorder(n);
    
    for (int i = 0; i < n; i++) {
        cin >> preorder[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }
    
    int first = getFirst(preorder, inorder, 0, n - 1, 0, n - 1);
    
    cout << first << endl;
    
    return 0;
    
}
