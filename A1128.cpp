#include <iostream>
#include <vector>
using namespace std;
const int MAX = 2000;

int main() {
    int k;
    scanf("%d", &k);
    
    for (int i = 0; i < k; i++) {
        int n;
        bool flag = true;
        scanf("%d", &n);
        vector<int> rows(n + 1);
        
        bool table1[MAX] = {false};
        bool table2[MAX] = {false};
        bool table3[MAX] = {false};

        for (int j = 1; j <= n; j++) {
            cin >> rows[j];
        }
        
        for (int column = 1; column <= n; column++) {
            int row = rows[column];
            if (table1[row] || table2[row - column + 1000] || table3[row + column]) {
                flag = false;
                break;
            }
            table1[row] = true;
            table2[row - column + 1000] = true;
            table3[row + column] = true;
        }
        
        if (flag) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}

/*
1
5 1 3 5 2 4
 */
