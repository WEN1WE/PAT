/*
 * 1. 左右子树不能只有一个存在，则树是唯一的
 * 2. 熟练建树
 * 3. 末尾加一个换行符
 */

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preorder(31);
vector<int> postorder(31);
vector<int> inorder;
bool FLAG = true;

TreeNode* buildTree(int preL, int preR, int postL, int postR) {
    if (preL > preR) {
        return NULL;
    }
    TreeNode* root = new TreeNode(preorder[preL]);
    if (preL == preR) {
        return root;
    }
    for (int i = postL; i <= postR; i++) {
        if (postorder[i] == preorder[preL + 1]) {
            int len = i - postL + 1;
            root->left = buildTree(preL + 1, preL + len, postL, i);
            root->right = buildTree(preL + len + 1, preR, i + 1, postR - 1);
            if ((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL)) {
                FLAG = false;
            }
            break;
        }
    }
    return root;
}

void getInorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    getInorder(root->left);
    inorder.push_back(root->val);
    getInorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        cin >> preorder[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> postorder[i];
    }
    TreeNode* root = buildTree(0, n - 1, 0, n - 1);
    getInorder(root);
    if (FLAG) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", inorder[i]);
    }
    printf("\n");
    
    return 0;
}
