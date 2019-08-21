/*
 * 1. 本题为构建AVL tree
 */

#include <iostream>
using namespace std;

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

TreeNode *rotateLeft(TreeNode *root) {
    TreeNode *t = root->right;
    root->right = t->left;
    t->left = root;
    return t;
}

TreeNode *rotateRight(TreeNode *root) {
    TreeNode *t = root->left;
    root->left = t->right;
    t->right = root;
    return t;
}

TreeNode *rotateRightLeft(TreeNode *root) {
    root->right = rotateRight(root->right);
    return rotateLeft(root);
}

TreeNode *rotateLeftRight(TreeNode *root) {
    root->left = rotateLeft(root->left);
    return rotateRight(root);
}

int getHeight(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}

TreeNode *insert(TreeNode *root, int value) {
    if (root == NULL) {
        root = new TreeNode(value);
        return root;
    }
    
    if (value < root->value) {
        root->left = insert(root->left, value);
        if (getHeight(root->left) - getHeight(root->right) == 2) 
            root = value < root->left->value ? rotateRight(root) : rotateLeftRight(root);
    } else {
        root->right = insert(root->right, value);
        if (getHeight(root->right) - getHeight(root->left) == 2) {
            root = value > root->right->value ? rotateLeft(root) : rotateRightLeft(root);
        }
    }
    return root;
}

int main() {
    int n, value;
    cin >> n;
    TreeNode* root = NULL;
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }
    printf("%d", root->value);
    return 0;
}
