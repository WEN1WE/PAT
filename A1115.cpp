/*
 * 1. 建立二叉搜索树
 * 2. 深度优先搜索进行1遍历
 */

#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1010;
vector<int> COUNT(MAX);
int MAXLEVEL = 0;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

TreeNode* insert(TreeNode* root, int value) {
    if (root == NULL) {
        return new TreeNode(value);
    }
    if (value <= root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

void dfs(TreeNode* root, int level) {
    if (root == NULL) {
        return;
    }
    COUNT[level]++;
    MAXLEVEL = max(level, MAXLEVEL);
    dfs(root->left, level + 1);
    dfs(root->right, level + 1);
}

int main() {
    int n, value;
    TreeNode* root = NULL;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }
    
    dfs(root, 1);
    printf("%d + %d = %d\n", COUNT[MAXLEVEL], COUNT[MAXLEVEL - 1], COUNT[MAXLEVEL] + COUNT[MAXLEVEL - 1]);
    return 0;
}
