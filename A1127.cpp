/*
 * 1. 层序遍历是，NULL不要加入队列中，只加入有效节点
 * 2. 使用两个队列，交替存储每一层
 */


#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorder(31);
vector<int> postorder(31);
vector<int> result;

TreeNode* buildTree(int inL, int inR, int postL, int postR) {
    if (inL > inR) {
        return NULL;
    }
    TreeNode* root = new TreeNode(postorder[postR]);
    
    for (int i = inL; i <= inR; i++) {
        if (inorder[i] == root->val) {
            int len = i - inL;
            root->left = buildTree(inL, i - 1, postL, postL + len - 1);
            root->right = buildTree(i + 1, inR, postL + len, postR - 1);
            break;
        }
    }
    return root;
}

void bfs(TreeNode* root) {
    queue<TreeNode *> q1, q2;
    vector<int> temp;
    bool flag = true;
    q1.push(root);
    
    while (!q1.empty() || !q2.empty()) {
        if (!q1.empty()) {
            flag = true;
            while (!q1.empty()) {
                TreeNode* node = q1.front();
                temp.push_back(node->val);
                if (node->left != NULL)
                    q2.push(node->left);
                if (node->right != NULL)
                    q2.push(node->right);
                q1.pop();
            }
        } else {
            flag = false;
            while (!q2.empty()) {
                TreeNode* node = q2.front();
                temp.push_back(node->val);
                if (node->left != NULL)
                    q1.push(node->left);
                if (node->right != NULL)
                    q1.push(node->right);
                q2.pop();
            }
        }
        if (flag) {
            reverse(temp.begin(), temp.end());
        }
        
        for (auto e : temp) {
            result.push_back(e);
        }
        temp.clear();
    }

}

int main() {

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> postorder[i];
    }
    TreeNode* root = buildTree(0, n - 1, 0, n - 1);
    
    bfs(root);
    
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", result[i]);
    }
    printf("\n");
    return 0;
}
