/*
 * 1. vector 存储字符数组不方便，则使用二维数组
 * 2. 将名字用下标代替，操作简单
 * 3. strcmp 在 #include <string.h> 中
 */

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAXCOURSES = 2510;
const int MAXSTUDENTS = 40010;
vector<int> courses[MAXCOURSES];
char names[MAXSTUDENTS][5];

bool cmp(int a, int b) {
    return strcmp(names[a], names[b]) < 0;
}

int main() {
    int n, k, registered, courseID;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s %d", names[i], &registered);
        for (int j = 0; j < registered; j++) {
            scanf("%d", &courseID);
            courses[courseID].push_back(i);
        }
    }

    for (int i = 1; i <= k; i++) {
        printf("%d %d\n", i, courses[i].size());
        sort(courses[i].begin(), courses[i].end(), cmp);
        for (int j = 0; j < courses[i].size(); j++) {
            printf("%s\n", names[courses[i][j]]);
        }
    }
    return 0;
}
