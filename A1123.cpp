/*
 * 1. 思考，如何判断完全二叉树
 * 2. 更好的思路：判断是不是完全二叉树，就看在出现了一个孩子为空的结点之后是否还会出现孩子结点不为空的结点，如果出现了就不是完全二叉树。
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {};
};

TreeNode* leftRotation (TreeNode* root) {
    TreeNode* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    return temp;
}

TreeNode* rightRotation(TreeNode* root) {
    TreeNode* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    return temp;
}

TreeNode* leftRightRotation(TreeNode* root) {
    root->left = leftRotation(root->left);
    return rightRotation(root);
}

TreeNode* rightLeftRotation(TreeNode* root) {
    root->right = rightRotation(root->right);
    return leftRotation(root);
}

int getHeight(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

TreeNode* insert(int value, TreeNode* root) {
    if (root == NULL) {
        return new TreeNode(value);
    }
    if (value > root->value) {
        root->right = insert(value, root->right);
        if (getHeight(root->right) - getHeight(root->left) > 1) {
            root = value > root->right->value ? leftRotation(root) : rightLeftRotation(root);
        }
    } else {
        root->left = insert(value, root->left);
        if (getHeight(root->left) - getHeight(root->right) > 1) {
            root = value < root->left->value ? rightRotation(root) : leftRightRotation(root);
        }
    }
    return root;
}

vector<int> levelorder;
void getLevelorder(TreeNode *root) {
    levelorder.push_back(-1);
    queue<TreeNode *> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* current = q.front();
        levelorder.push_back(current->value);
        q.pop();
        if (current->left != NULL) {
            q.push(current->left);
        }
        if (current->right != NULL) {
            q.push(current->right);
        }
    }
}

bool isComplete(TreeNode* root, int index) {
    if (root == NULL) {
        return true;
    }
    if (root->value != levelorder[index]) {
        return false;
    }
    return isComplete(root->left, index * 2) && isComplete(root->right, index * 2 + 1);
}

int main() {
    int n, value;
    scanf("%d", &n);
    TreeNode* root = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(value, root);
    }
    
    getLevelorder(root);
    
    for (int i = 1; i <= n; i++) {
        if (i != 1) {
            printf(" ");
        }
        printf("%d", levelorder[i]);
    }
    printf("\n");
    if (isComplete(root, 1)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
