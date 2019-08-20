/*
 * 1. strlen 在哪个库中？ // #include <string.h>
 * 2. char str[10] 来读字符串时，以空格和换行符为分割
 */

#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preorder;
vector<int> inorder;
vector<int> postorder;

TreeNode* buildTree(int pStart, int pEnd, int iStart, int iEnd) {
    if (pStart > pEnd) {
        return NULL;
    }
    TreeNode* root = new TreeNode(preorder[pStart]);
    
    for (int i = iStart; i <= iEnd; i++) {
        if (inorder[i] == root->val) {
            int len = i - iStart;
            root->left = buildTree(pStart + 1, pStart + len, iStart, i - 1);
            root->right = buildTree(pStart + len + 1, pEnd, i + 1, iEnd);
            break;
        }
    }
    return root;
}

void getPostorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    getPostorder(root->left);
    getPostorder(root->right);
    postorder.push_back(root->val);
}

int main() {
    int n, val; 
    scanf("%d\n", &n);
    char str[10];
    stack<int> st;
    
    for (int i = 0; i < n * 2; i++) {
        scanf("%s", str); 
        if (strlen(str) == 4) {
            scanf("%d", &val);
            preorder.push_back(val);
            st.push(val);
        } else {
            val = st.top();
            inorder.push_back(val);
            st.pop();
        }
    }
    TreeNode* root = buildTree(0, n - 1, 0, n - 1);
    getPostorder(root);
    
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", postorder[i]);
    }
    
    return 0;
}
