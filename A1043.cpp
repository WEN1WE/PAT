/*
 * 1. 对二叉搜索树进行中序遍历，其实也就是对他进行排列
 * 2. 其镜像也就是对其进行递减排列
 * 3. 由于有重复的元素，所以与原来的建树不一样
 * 4. 本题如果采用中序和前序进行建树，有两种情况，比较麻烦（因为有重复元素，重复元素归为哪边的问题）
 * 5. 本题题意不明，没有说是插入序列，但是按照先序遍历进行插入，就是可以得到搜索二叉树，因为根的位置肯定最先插入
 * 6. 将后序和判断合为一步来做
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



