/*
 * 1. 二维数组自动初始化为false;
 * 2. 思考，如何快速写好逻辑
 */
#include <iostream>
#include <vector>
using namespace std;

int Nv;
bool graph[201][210];

bool checkClique(vector<int> & record) {
    for (auto e1 : record) {
        for (auto e2 : record) {
           if (e1 != e2 && !graph[e1][e2]) {
               return false;
           }
       }
    }
    return true;
}

bool checkMaximal(vector<int> & record) {
    for (int i = 1; i <= Nv; i++) {
        int flag = true;
        for (auto e : record) {
            flag = flag && graph[e][i];
        }
        if (flag) {
            return false;
        }
    }
    return true;
}


int main() {
    int Ne;
    scanf("%d %d", &Nv, &Ne);
    for (int i = 0; i < Ne; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        graph[v1][v2] = true;
        graph[v2][v1] = true;
    }
    
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int k;
        scanf("%d", &k);
        vector<int> record(k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &record[j]);
        }
        
        if (!checkClique(record)) {
            printf("Not a Clique\n");
        } else {
            if (checkMaximal(record)) {
                printf("Yes\n");
            } else {
                printf("Not Maximal\n");
            }
        }
    }
    return 0;
}
