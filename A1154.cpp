/*
 * 1. 本题数据大，容易超时
 * 2. 使用邻接表存
 * 3. 递归要学会寻找等价条件，递归一定要找好等价条件，本题的等价条件想当然了
 * 4. 做复杂了，其实只用比较给的边就行
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int MAX = 100100;
vector<vector<int>> graph(MAX);

bool dfs(int v, vector<int> & color, vector<bool> & visited) {
    if (visited[v] || graph[v].empty()) {
        visited[v] = true;
        return true;
    }
    visited[v] = true;
    for (auto w : graph[v]) {
        if (color[v] == color[w]) {
            return false;
        }
        if (!dfs(w, color, visited)) {
            return false;
        }
    }
    return true;
}

int main() {
    int N, M, K;
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < M; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    
    scanf("%d", &K);
    
    for (int i = 0; i < K; i++) {
        bool flag = true;
        vector<int> color(N);
        vector<bool> visited(MAX);
        map<int, bool> mp;
        for (int j = 0; j < N; j++) {
            scanf("%d", &color[j]);
            mp[color[j]] = true;
        }
        
        for (int j = 0; j < N; j++) {
            if (!visited[j] && !dfs(j, color, visited)) {
                flag = false;
                printf("No\n");
                break;
            }
        }
        if (flag) {
            printf("%d-coloring\n", mp.size());
        }
        
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Pair {
	int end1;
	int end2;
};

bool check(vector<Pair> & record, vector<int> & color) {
	for (auto e : record) {
		if (color[e.end1] == color[e.end2]) {
			return false;
		}
	}
	return true;
}

int main() {
	int N, M, K;
	scanf("%d %d", &N, &M);
	vector<Pair> record(M);


	for (int i = 0; i < M; i++) {
		scanf("%d %d", &record[i].end1, &record[i].end2);
	}

	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		map<int, bool> mp;
		vector<int> color(N);
		for (int j = 0; j < N; j++) {
			scanf("%d", &color[j]);
			mp[color[j]] = true;
		}

		if (check(record, color)) {
			printf("%d-coloring\n", mp.size());
		}
		else {
			printf("No\n");
		}
	}
	system("pause");
	return 0;

}


