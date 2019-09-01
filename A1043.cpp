/*
 * 1. 对二叉搜索树进行中序遍历，其实也就是对他进行排列
 * 2. 其镜像也就是对其进行递减排列
 * 3. 由于有重复的元素，所以与原来的建树不一样
 * 4. 本题如果采用中序和前序进行建树，有两种情况，比较麻烦（因为有重复元素，重复元素归为哪边的问题）
 * 5. 本题题意不明，没有说是插入序列，但是按照先序遍历进行插入，就是可以得到搜索二叉树，因为根的位置肯定最先插入
 * 6. 将后序和判断合为一步来做
 * 7. 对二叉搜索树，不管是镜像还是本身，进行先序遍历，就是插入序列
 * 8. 对于镜像问题，其实也就是左右交换问题，不用再建树
 */

#include <iostream>
#include <vector>
using namespace std;

bool IS_MIRROR;
vector<int> preorder, postorder;

void getPost(int start, int end) {
    if (start > end) {
        return;
    }
    int rightStart = start + 1, leftEnd = end;
    if (!IS_MIRROR) {
        while (rightStart <= end && preorder[start] > preorder[rightStart]) rightStart++;
        while (leftEnd > start && preorder[start] <= preorder[leftEnd]) leftEnd--;
    } else {
        while (rightStart <= end && preorder[start] <= preorder[rightStart]) rightStart++;
        while (leftEnd > start && preorder[start] > preorder[leftEnd]) leftEnd--;
    }
    if (rightStart - leftEnd != 1) {
        return;
    }
    getPost(start + 1, leftEnd);
    getPost(rightStart, end);
    postorder.push_back(preorder[start]);
}
    
int main() {
    int n, value;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> value;
        preorder.push_back(value);
    }
    if (preorder.size() >= 2) {
        IS_MIRROR = preorder[0] < preorder[1];
    }
    
    getPost(0, n - 1);
    if (postorder.size() == n) {
        printf("YES\n");
        for (int i = 0; i < n; i++) {
            if (i != 0) {
                printf(" ");
            }
            printf("%d", postorder[i]);
        }
    } else {
        printf("NO");
    }
    
    return 0;
}


#include <iostream>
#include <vector>
using namespace std;

vector<int> preorder;
vector<int> postorder;
vector<int> mirrorPreorder;
vector<int> mirrorPostorder;

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

TreeNode* insert(TreeNode* root, int value) {
    if (root == NULL) {
        return new TreeNode(value);
    }
    if (root->value > value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

void getPreorder(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    preorder.push_back(root->value);
    getPreorder(root->left);
    getPreorder(root->right);
}

void getPostorder(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    getPostorder(root->left);
    getPostorder(root->right);
    postorder.push_back(root->value);
}

void getMirrorPreorder(TreeNode * root) {
    if (root == NULL) {
        return;
    }
    mirrorPreorder.push_back(root->value);
    getMirrorPreorder(root->right);
    getMirrorPreorder(root->left);
}

void getMirrorPostorder(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    getMirrorPostorder(root->right);
    getMirrorPostorder(root->left);
    mirrorPostorder.push_back(root->value);
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
    int N;
    scanf("%d", &N);
    vector<int> sequence(N);

    TreeNode* root = NULL;
    for (int i = 0; i < N; i++) {
        scanf("%d", &sequence[i]);
        root = insert(root, sequence[i]);
    }
    
    getPreorder(root);
    vector<int> temp = preorder;
    if (sequence == preorder) {
        printf("YES\n");
        getPostorder(root);
        print(postorder);
    } else {
        getMirrorPreorder(root);
        if (sequence == mirrorPreorder) {
            printf("YES\n");
            getMirrorPostorder(root);
            print(mirrorPostorder);
        } else {
            printf("NO\n");
        }
    }
    return 0;
}


