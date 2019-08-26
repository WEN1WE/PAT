/*
 * 1. 使用二维数组来存图的关系
 * 2. 还是数据没读完就返回的问题
 * 3. 本题使用set更加方便
 * 4. Hamiltonian 的特点是访问的总节点上为 n + 1,  而且每个节点被访问一次
 * 5. 理清题意，选择合适的结构
 */

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
    bool graph[210][210];

    for (int i = 1; i <= m; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        graph[v1][v2] = true;
        graph[v2][v1] = true;
    }

    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        bool flag = true;
        int len;
        scanf("%d", &len);
        vector<int> path(len);
        set<int> st;
        for (int j = 0; j < len; j++) {
            scanf("%d", &path[j]);
            st.insert(path[j]);
        }

        if (len - 1 != n || st.size() != n || path[0] != path[len - 1]) {
            printf("NO\n");
            continue;
        }

        for (int j = 0; j < len - 1; j++) {
            if (!graph[path[j]][path[j + 1]]) {
                flag = false;
                printf("NO\n");
                break;
            }
        }
        if (flag) {
            printf("YES\n");
        }
    }
    return 0;
}
