/*
 * 1. 完美二叉树，层序遍历，可以递归，直接得到后序遍历
 * 2. 也可以分为两步来做
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


#include <iostream>
#include <vector>
using namespace std;

int M, N;
vector<int> levelorder;
vector<int> postorder;

bool isMaxHeap;

bool check(int root) {
	if (2 * root > N) {
		return true;
	}
	if (levelorder[root] > levelorder[root * 2] != isMaxHeap) {
		return false;
	}
	if (2 * root + 1 <= N) {
		if (levelorder[root] > levelorder[root * 2 + 1] != isMaxHeap) {
			return false;
		}
	}
	return check(root * 2) && check(root * 2 + 1);
}

void getPostorder(int root) {
	if (root > N) {
		return;
	}
	getPostorder(2 * root);
	getPostorder(2 * root + 1);
	postorder.push_back(levelorder[root]);
}

void print() {
	for (int i = 0; i < N; i++) {
		if (i != 0) {
			printf(" ");
		}
		printf("%d", postorder[i]);
	}
	printf("\n");
	postorder.clear();
}

int main() {
	scanf("%d %d", &M, &N);
	levelorder.resize(N + 1);

	for (int i = 0; i < M; i++) {
		bool isHeap;
		for (int j = 1; j <= N; j++) {
			scanf("%d", &levelorder[j]);
		}
		isMaxHeap = levelorder[1] > levelorder[2];
		isHeap = check(1);
		if (isHeap) {
			if (isMaxHeap) {
				printf("Max Heap\n");
			}
			else {
				printf("Min Heap\n");
			}
		}
		else {
			printf("Not Heap\n");
		}
		getPostorder(1);
		print();
	}

	system("pause");
	return 0;
}
