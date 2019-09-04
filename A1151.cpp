/*
 * 1. 方法1 996ms, 先记录，再比较的方法太低效
 * 2. 方法2 100ms, 此方法比较高效，使用递归的方法直接找出LCA
 * 3. 写程序要严谨， 错一个字母就错来
 * 4. 本题还可以通过先存储，再找路径的方法
 */

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> inorder;
vector<int> preorder;
map<int, int> mp;

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(int inL, int inR, int preL, int preR) {
    if (inL > inR) {
        return NULL;
    }
    TreeNode* root = new TreeNode(preorder[preL]);
    
    for (int i = inL; i <= inR; i++) {
        if (inorder[i] == root->value) {
            int len = i - inL;
            root->left = buildTree(inL, i - 1, preL + 1, preL + len);
            root->right = buildTree(i + 1, inR, preL + len + 1, preR);
            break;
        }
    }
    return root;
}

void buildMap(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    if (root->left != NULL) {
        mp[root->left->value] = root->value;
    }
    if (root->right != NULL) {
        mp[root->right->value] = root->value;
    }
    buildMap(root->left);
    buildMap(root->right);
}

void findPath(int value, int root, vector<int> & path) {
    while (value != root) {
        path.push_back(value);
        value = mp[value];
    }
    path.push_back(root);
}

int findDeepest(vector<int> & path1, vector<int> & path2) {
    reverse(path1.begin(), path1.end());
    reverse(path2.begin(), path2.end());
    int len = min(path1.size(), path2.size());
    int result = 0;
    
    for (int i = 0; i < len; i++) {
        if (path1[i] == path2[i]) {
            result = path1[i];
        } else {
            break;
        }
    }
    return result;
}

int main() {
    int m, n, value;
    scanf("%d %d", &m, &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        inorder.push_back(value);
    }
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        preorder.push_back(value);
    }
    TreeNode* root = buildTree(0, n - 1, 0, n - 1);
    buildMap(root);
    mp[root->value] = -1;
    
    for (int i = 0; i < m; i++) {
        bool flag1 = false;
        bool flag2 = false;
        vector<int> path1;
        vector<int> path2;
        
        int u, v, deepest;
        scanf("%d %d", &u, &v);
        flag1 = mp.find(u) == mp.end();
        flag2 = mp.find(v) == mp.end();
        
        if (flag1 && flag2) {
            printf("ERROR: %d and %d are not found.", u, v);
        } else if (flag1) {
            printf("ERROR: %d is not found.", u);
        } else if (flag2) {
            printf("ERROR: %d is not found.", v);
        } else {
            findPath(u, root->value, path1);
            findPath(v, root->value, path2);
            deepest = findDeepest(path1, path2);
            if (deepest == u) {
                printf("%d is an ancestor of %d.", u, v);
            } else if (deepest == v) {
                printf("%d is an ancestor of %d.", v, u);
            } else {
                printf("LCA of %d and %d is %d.", u, v, deepest);
            }
        }
        printf("\n");
    }
    return 0;
}

/*
6 8
7 2 3 4 6 5 1 8
5 3 7 2 6 4 8 1
2 6
8 1
7 9
12 -3
0 8
4 4
 */

#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<int> inorder;
vector<int> preorder;
map<int, bool> mp;

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(int inL, int inR, int preL, int preR) {
    if (preL > preR) {
        return NULL;
    }
    TreeNode* root = new TreeNode(preorder[preL]);

    for (int i = inL; i <= inR; i++) {
        if (inorder[i] == root->value) {
            int len = i - inL;
            root->left = buildTree(inL, i - 1, preL + 1, preL + len);
            root->right = buildTree(i + 1, inR, preL + len + 1, preR);
            break;
        }
    }
    return root;
}

TreeNode* LCA(TreeNode* root, int val1, int val2) {
    if (!root || root->value == val1 || root->value == val2)
        return root;

    auto L = LCA(root->left, val1, val2);
    auto R = LCA(root->right, val1, val2);

    if (L && R)
        return root;
    return L ? L : R;
}

int main() {
    int m, n, value;
    scanf("%d %d", &m, &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        mp[value] = true;
        inorder.push_back(value);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        preorder.push_back(value);
    }
    TreeNode* root = buildTree(0, n - 1, 0, n - 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        int flag1 = mp.find(u) == mp.end();
        int flag2 = mp.find(v) == mp.end();

        if (flag1 && flag2) {
            printf("ERROR: %d and %d are not found.", u, v);
        } else if (flag1) {
            printf("ERROR: %d is not found.", u);
        } else if (flag2) {
            printf("ERROR: %d is not found.", v);
        } else {
            int lowest = LCA(root, u, v)->value;
            if (u == lowest) {
                printf("%d is an ancestor of %d.", u, v);
            } else if (v == lowest) {
                printf("%d is an ancestor of %d.", v, u);
            } else {
                printf("LCA of %d and %d is %d.", u, v, lowest);
            }
        }
        printf("\n");
    }
    return 0;
}


#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode(int x) : value(x), left(NULL), right(NULL), parent(NULL) {}
};
map<int, TreeNode*> hashTable;
vector<int> inorder;
vector<int> preorder;

TreeNode* buildTree(int inL, int inR, int preL, int preR) {
    if (inL > inR) {
        return NULL;
    }
    TreeNode *root = new TreeNode(preorder[preL]);
    hashTable[root->value] = root;
    for (int i = inL; i <= inR; i++) {
        if (inorder[i] == root->value) {
            int len = i - inL;
            root->left = buildTree(inL, i - 1, preL + 1, preL + len);
            if (root->left != NULL) {
                root->left->parent = root;
                hashTable[root->left->value] = root->left;
            }
            root->right = buildTree(i + 1, inR, preL + len + 1, preR);
            if (root->right != NULL) {
                root->right->parent = root;
                hashTable[root->right->value] = root->right;
            }
        }
    }
    return root;
}

void findPath(int v, vector<int> & path) {
    TreeNode *node = hashTable[v];
    while (node != NULL) {
        path.push_back(node->value);
        node = node->parent;
    }
}

int findAncestor(vector<int> & pathU, vector<int> & pathV) {
    int p1 = pathU.size() - 1;
    int p2 = pathV.size() - 1;
    int result = -1;
    while (p1 >= 0 && p2 >= 0) {
        if (pathU[p1] == pathV[p2]) {
            result =  pathU[p1];
            p1--;
            p2--;
        } else {
            break;
        }
    }
    return result;
}

int main() {
    int M, N;
    scanf("%d %d", &M, &N);
    map<int, bool> mp;
    inorder.resize(N);
    preorder.resize(N);
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &inorder[i]);
        mp[inorder[i]] = true;
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &preorder[i]);
    }
    TreeNode *root = buildTree(0, N - 1, 0, N -1);
    
    for (int i = 0; i < M; i++) {
        int u, v;
        bool flag1, flag2;
        int ancestor;
        vector<int> pathU;
        vector<int> pathV;
        
        scanf("%d %d", &u, &v);
        flag1 = mp.find(u) == mp.end();
        flag2 = mp.find(v) == mp.end();
        
        if (flag1 && flag2) {
            printf("ERROR: %d and %d are not found.\n", u, v);
        } else if (flag1) {
            printf("ERROR: %d is not found.\n", u);
        } else if (flag2) {
            printf("ERROR: %d is not found.\n", v);
        } else {
            findPath(u, pathU);
            findPath(v, pathV);
            ancestor = findAncestor(pathU, pathV);
            pathU.clear();
            pathV.clear();
            if (ancestor == u) {
                printf("%d is an ancestor of %d.\n", u, v);
            } else if (ancestor == v) {
                printf("%d is an ancestor of %d.\n", v, u);
            } else {
                printf("LCA of %d and %d is %d.\n", u, v, ancestor);
            }
        }
    }
    
    return 0;
    
}
