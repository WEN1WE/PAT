/*
 * 1. 本题可以不用建树，直接dfs
 * 2. 本题可以分开判断
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1010;
vector<int> leverorder(MAX);
int N;

bool cmp(int x, int y) {
    return x > y;
}

bool flag;
bool isHeap = true;
vector<int> result;
void dfs(int root) {
    if (root * 2 > N) {
        result.push_back(leverorder[root]);
        
        if (isHeap) {
            vector<int> temp;
            temp = result;
            if (flag) {
                sort(temp.begin(), temp.end(), cmp);
            } else {
                sort(temp.begin(), temp.end());
            }
            if (temp != result) {
                isHeap = false;
            }
        }
        
        for (int i = 0; i < result.size(); i++) {
            if (i != 0) {
                printf(" ");
            }
            printf("%d", result[i]);
        }
        printf("\n");
        result.pop_back();
    }
    result.push_back(leverorder[root]);
    if (root * 2 + 1 <= N)
        dfs(root * 2 + 1);
    if (root * 2 <= N)
        dfs(root * 2);
    result.pop_back();
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &leverorder[i]);
    }
    flag = leverorder[1] > leverorder[2];
    dfs(1);
    if (!isHeap) {
        printf("Not Heap\n");
    } else {
        if (flag) {
            printf("Max Heap\n");
        } else {
            printf("Min Heap\n");
        }
    }
}


#include <iostream>
#include <vector>
using namespace std;

int N;
bool isMaxHeap;

vector<int> levelorder;

bool checkHeap(int root) {
    int left = 2 * root;
    int right = 2 * root + 1;
    if (left > N) {
        return true;
    }
    if (levelorder[root] > levelorder[left] != isMaxHeap) {
        return false;
    }
    if (root * 2 + 1 <= N) {
        if (levelorder[root] > levelorder[right] != isMaxHeap) {
            return false;
        }
    }
    return checkHeap(left) && checkHeap(right);
}

vector<int> path;
void print() {
    for (int i = 0; i < path.size(); i++) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", path[i]);
    }
    printf("\n");
}

void dfs(int root) {
    if(root > N) {
        return;
    }
    
    path.push_back(levelorder[root]);
    if (root * 2 > N) {
        print();
        path.pop_back();
        return;
    }
    
    dfs(root * 2 + 1);
    dfs(root * 2);
    path.pop_back();
}



int main() {
    bool isHeap;
    scanf("%d", &N);
    levelorder.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &levelorder[i]);
    }
    isMaxHeap = levelorder[1] > levelorder[2];
    isHeap = checkHeap(1);
    
    dfs(1);
    
    if (isHeap) {
        if (isMaxHeap) {
            printf("Max Heap\n");
        } else {
            printf("Min Heap\n");
        }
    } else {
        printf("Not Heap\n");
    }

}
