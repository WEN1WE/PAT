/*
 * 1. 层序遍历是，NULL不要加入队列中，只加入有效节点
 * 2. 使用两个队列，交替存储每一层
 * 3. 本题也可以给节点加一个深度，来标示每一层
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


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> inorder;
vector<int> postorder;
vector<int> zigzagging;

struct TreeNode {
    int value;
    int level;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : value(x), level(-1), left(NULL), right(NULL) {}
};

TreeNode *buildTree(int inL, int inR, int postL, int postR) {
    if (inL > inR) {
        return NULL;
    }
    TreeNode *root = new TreeNode(postorder[postR]);
    for (int i = inL; i<= inR; i++) {
        if (inorder[i] == root->value) {
            int len = i - inL;
            root->left = buildTree(inL, i - 1, postL, postL + len - 1);
            root->right = buildTree(i + 1, inR, postL + len, postR - 1);
        }
    }
    return root;
}

vector<int> record[50];
int deepest = -1;
void traversal(TreeNode *root) {
    root->level = 1;
    queue<TreeNode *> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* node = q.front();
        deepest = max(node->level, deepest);
        record[node->level].push_back(node->value);
        q.pop();
        
        if (node->left != NULL) {
            node->left->level = node->level + 1;
            q.push(node->left);
        }
        if (node->right != NULL) {
            node->right->level = node->level + 1;
            q.push(node->right);
        }
    }
}

void addTo(vector<int> & v) {
    for (auto e : v) {
        zigzagging.push_back(e);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    inorder.resize(N);
    postorder.resize(N);
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &inorder[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &postorder[i]);
    }
    TreeNode *root = buildTree(0, N - 1, 0, N - 1);
    traversal(root);
    
    for (int i = 1; i <= deepest; i++) {
        if (i % 2 != 0) {
            reverse(record[i].begin(), record[i].end());
        }
        addTo(record[i]);
    }
    
    for (int i = 0; i < N; i++) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", zigzagging[i]);
    }
    printf("\n");
    return 0;
}
