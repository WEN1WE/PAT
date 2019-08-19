/*
 * 1. return NULL;
 * 2. 本题主要是常规的树的转换
 */

#include <iostream>
#include <queue>
#include <vector>
using namespace std;


bool FLAG = false;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode* buildTree(vector<int> &postorder, vector<int> &inorder, int pStart, int pEnd, int iStart, int iEnd) {
    if (pStart > pEnd) {
        return NULL;
    }
    TreeNode *root = new TreeNode;
    root->val = postorder[pEnd];
    
    for (int i = iStart; i <= iEnd; i++) {
        if (inorder[i] == root->val) {
            root->left = buildTree(postorder, inorder, pStart, pStart + (i - iStart) - 1, iStart, i - 1);
            root->right = buildTree(postorder, inorder, pStart + (i - iStart), pEnd - 1, i + 1, iEnd);
            break;
        }
    }
    return root;
} 

void bfs(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (FLAG) {
            printf(" ");
        }
        printf("%d", node->val);
        FLAG = true;
        
        if (node->left != NULL) {
            q.push(node->left);
        }
        if (node->right != NULL) {
            q.push(node->right);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> postorder(n);
    vector<int> inorder(n);
    
    for (int i = 0; i < n; i++) {
        cin >> postorder[i];
    }
    
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }
    
    TreeNode* root = buildTree(postorder, inorder, 0, n - 1, 0, n - 1);
    bfs(root);
    return 0;
}
