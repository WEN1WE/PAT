/*
 * 1. return NULL;
 * 2. 本题主要是常规的树的转换
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> postorder;
vector<int> inorder;
vector<int> levelorder;
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {};
};

TreeNode* buildTree(int postL, int postR, int inL, int inR) {
    if (postL > postR) {
        return NULL;
    }
    TreeNode* root = new TreeNode(postorder[postR]);
    for (int i = inL; i <= inR; i++) {
        if (inorder[i] == root->value) {
            int len = i - inL;
            root->left = buildTree(postL, postL + len - 1, inL, i - 1);
            root->right = buildTree(postL + len, postR - 1, i + 1, inR);
        }
    }
    return root;
}

void bfs(TreeNode *root) {
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* node = q.front();
        levelorder.push_back(node->value);
        q.pop();
        if (node->left != NULL) {
            q.push(node->left);
        }
        if (node->right != NULL) {
            q.push(node->right);
        }
    }
    
}

int main() {
    int N; 
    scanf("%d", &N);
    postorder.resize(N);
    inorder.resize(N);
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &postorder[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &inorder[i]);
    }
    TreeNode* root = buildTree(0, N - 1, 0, N - 1);
    bfs(root);
    
    for (int i = 0; i < N; i++) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", levelorder[i]);
    }
    return 0;
}
