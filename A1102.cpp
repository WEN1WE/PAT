/*
 * 1. 二叉树的静态写法, 此时有一张表记录着节点的左右孩子
 * 2. vector<TreeNode> nodes(n); // vector中结构体可以直接赋值，不用初始化，像使用数组一样
 * 3. int a[n]={0}; // 注意n必须为const类型，否则错误
 * 4. 读入数据的时候就把左右对调
 * 5. 根据根结点没有在数据中出现的特点，找到根
 */

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int left;
    int right;
};
vector<int> leverorder;
vector<int> inorder;

void getLeverorder(vector<TreeNode> & nodes, int root) {
    int val;
    queue<int> q;
    q.push(root);
    
    while (!q.empty()) {
        val = q.front();
        leverorder.push_back(val);
        if (nodes[val].left != -1)
            q.push(nodes[val].left);
        if (nodes[val].right != -1)
            q.push(nodes[val].right);
        q.pop();
    }
}

void getInorder(vector<TreeNode> & nodes, int root) {
    if (root == -1) {
        return;
    } 
    getInorder(nodes, nodes[root].left);
    inorder.push_back(root);
    getInorder(nodes, nodes[root].right);
}

void print(vector<int> & order) {
    int n = order.size();
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", order[i]);
    }
    printf("\n");
}

int main() {
    int n = 0, root = 0;
    string left, right;
    scanf("%d", &n);
    vector<TreeNode> nodes(n);

    bool table[20] = {false};

    for (int i = 0; i < n; i++) {
        cin >> right >> left;
        nodes[i].left = left == "-" ? -1 : stoi(left);
        table[nodes[i].left + 1] = true;
        nodes[i].right = right == "-" ? -1 : stoi(right);
        table[nodes[i].right + 1] = true;
    }
    
    for (int i = 0; i < n; i++) {
        if (!table[i + 1]) {
            root = i;
            break;
        }
    }
    
    getLeverorder(nodes, root);
    getInorder(nodes, root);
    
    print(leverorder);
    print(inorder);
    
    return 0;
}


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int left = -1;
    int right = -1;
};
vector<TreeNode> tree;
vector<int> levelorder;
vector<int> inorder;

void getLevelorder(int root) {
    queue<int> q;
    q.push(root);
    
    while (!q.empty()) {
        int node = q.front();
        levelorder.push_back(node);
        q.pop();
        if (tree[node].left != -1) {
            q.push(tree[node].left);
        }
        if (tree[node].right != -1) {
            q.push(tree[node].right);
        }
    }
}

void getInorder(int root) {
    if (root == -1) {
        return;
    }
    getInorder(tree[root].left);
    inorder.push_back(root);
    getInorder(tree[root].right);
}

void print(vector<int> & v) {
    for (int i = 0; i < v.size(); i++) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", v[i]);
    }
    printf("\n");
}

int main() {
    int N, root = -1;
    scanf("%d", &N);
    vector<bool> table(N);
    tree.resize(N);
    
    for (int i = 0; i < N; i++) {
        string left, right;
        cin >> right >> left;
        if (left != "-") {
            tree[i].left = stoi(left);
            table[stoi(left)] = true;
        }
        if (right != "-") {
            tree[i].right = stoi(right);
            table[stoi(right)] = true;
        }
    }
    
    for(int i = 0; i < N; i++) {
        if (!table[i]) {
            root = i;
            break;
        }
    }
    getLevelorder(root);
    getInorder(root);
    
    print(levelorder);
    print(inorder);
    
    return 0;
}
