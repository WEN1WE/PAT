/*
 * 1. 完美二叉树，层序遍历，可以递归，直接得到后序遍历
 */

#include <iostream>
#include <vector>
using namespace std;

int n;
const int MAX = 1010;

bool flag1 = true;
bool flag2 = true;
vector<int> postorder;
vector<int> leverorder(MAX);

void getPostorder(int root) {
    if (2 * root > n) {
        postorder.push_back(leverorder[root]);
        return;
    }
    
    if (leverorder[root * 2] > leverorder[root]) {
        flag1 = false;
    }
    if (leverorder[root * 2] < leverorder[root]) {
        flag2 = false;
    }
    
    getPostorder(root * 2);
    if (2 * root + 1 <= n) {
        if (leverorder[root * 2 + 1] > leverorder[root]) {
            flag1 = false;
        }
        if (leverorder[root * 2 + 1] < leverorder[root]) {
            flag2 = false;
        }
        
        getPostorder(root * 2 + 1);
    }
    postorder.push_back(leverorder[root]);
}


int main() {
    int m, value;
    scanf("%d %d", &m, &n);
    
    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &leverorder[j]);
        }
        getPostorder(1);
        if (flag1) {
            printf("Max Heap\n");
        } else if (flag2) {
            printf("Min Heap\n");
        } else {
            printf("Not Heap\n");
        }
        
        for (int j = 0; j < n; j++) {
            if (j != 0) {
                printf(" ");
            }
            printf("%d", postorder[j]);
        }
        printf("\n");
        postorder.clear();
        leverorder.clear();
        flag1 = true;
        flag2 = true;
    }
    return 0;
}
