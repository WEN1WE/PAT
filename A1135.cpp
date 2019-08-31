/*
 * 1. 思考，二叉搜索树应该怎么建树
 * 2. 思考，要不要考虑0 -0的情况 本题不用考虑
 * 3. 题目为什么不用检查平衡树？多写了检查平衡的函数
 * 4. 红黑树的平衡的意思，和平衡二叉树的平衡的意思不同
 */

#include <iostream>
#include <map>
using namespace std;

struct TreeNode {
    int value;
    bool color;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x, bool c) : value(x), color(c), left(NULL), right(NULL) {};
};

TreeNode* insert(int value, bool color, TreeNode *root) {
    if (root == NULL) {
        return new TreeNode(value, color);
    }
    if (root->value < value) {
        root->right = insert(value, color, root->right);
    } else {
        root->left = insert(value, color, root->left);
    }
    return root;
}

bool checkRoot(TreeNode *root) {
    return root->color;
}

/*
int getHeight(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

bool checkBalance(TreeNode *root) {
    if (root == NULL) {
        return true;
    }
    if (abs(getHeight(root->left) - getHeight(root->right)) > 1) {
        return false;
    } else {
        return checkBalance(root->left) && checkBalance(root->right);
    }
}
*/

bool getColor(TreeNode *root) {
    if (root == NULL) {
        return true;
    } else {
        return root->color;
    }
}

bool checkColor(TreeNode *root) {
    if (root == NULL) {
        return true;
    }
    if (!root->color) {
        if (!getColor(root->left) || !getColor(root->right)) {
            return false;
        }
    }
    return checkColor(root->left) && checkColor(root->right);
}

map<int, bool> mp;
void helper(TreeNode *root, int cnt) {
    if (root == NULL) {
        mp[cnt] = true;
        return;
    }
    if (root->color) {
        cnt++;
    }
    helper(root->left, cnt);
    helper(root->right, cnt);
}

bool checkPath(TreeNode *root) {
    helper(root, 0);
    bool result = mp.size() == 1;
    mp.clear();
    return result;
}

int main() {
    int K;
    scanf("%d", &K);
    
    for (int i = 0; i < K; i++) {
        TreeNode* root = NULL;
        int N, value;
        bool color;
        string s;
        scanf("%d", &N);
        
        for (int j = 0; j < N; j++) {
            cin >> s;
            if (s[0] == '-') {
                color = false;
                s = s.substr(1);
            } else {
                color = true;
            }
            value = stoi(s);
            root = insert(value, color, root);
        }
        if (!checkRoot(root) || !checkColor(root) || !checkPath(root)) {
            printf("No\n");
        } else {
            printf("Yes\n");
        }
    }
}
