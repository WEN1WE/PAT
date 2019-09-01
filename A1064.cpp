/*
 * 1. 本题使用递归的理解很复杂
 * 2. 可以对下标进行中序遍历，两次中序遍历的结果一样 例如下标(8 4 9 2 10 5 1 6 3 7) 对应的数字(0 1 2 3 4 5 6 7 8 9)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> sequence;
map<int, int> mp;
int N;
int cnt = 0;
void dfs(int root) {
    if (root > N) {
        return;
    }
    dfs(root * 2);
    mp[root] = sequence[cnt++];   // 本来中序遍历时，这里应该向inorder push_back的，也就是下标进入的顺序
    dfs(root * 2 + 1);
}


int main() {
    scanf("%d", &N);
    sequence.resize(N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &sequence[i]);
    }
    sort(sequence.begin(), sequence.end());
    dfs(1);
    for (int i = 1; i <= N; i++) {
        if (i != 1) {
            printf(" ");
        }
        printf("%d", mp[i]);
    }
    return 0;
}
