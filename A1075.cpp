/*
 * 1.int a[1000] = {0};就是把a中的1000个元素全部初始化为0，但是int a[1000] = {5};并不是把1000个元素初始化为5，它只是初始化第一个
 * 2. array 如何初始化为同一元素 int score[5] = {-2, -2, -2, -2, -2}; // {[0 ... 4] = -2}
 * 3. 这个问题的第一行是排名，不是 1 2 3 4 序号
 * 4. 题目有一个边界，编译通过，但是得分为0， 也要输出
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    int id;
    int score[5] = {-2, -2, -2, -2, -2}; // {[0 ... 4] = -2}
    int solved = 0;
    int total = 0;
    int rank;
    bool flag = false;
};

bool cmp(Student s1, Student s2) {
    if (s1.total == s2.total) {
        return s1.solved != s2.solved ? s1.solved > s2.solved : s1.id < s2.id;
    } else {
        return s1.total > s2.total;
    }
}

int main() {
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);
    int fullMark[k];
    vector<Student> students(n);

    for (int i = 0; i < k; i++) {
        scanf("%d", &fullMark[i]);
    }

    for (int i = 0; i < m; i++) {
        int id, problem, score;
        scanf("%d %d %d", &id, &problem, &score);
        students[id - 1].id = id;
        if (students[id - 1].score[problem - 1] < score) {
            students[id - 1].score[problem - 1] = score;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            int temp = students[i].score[j];
            if (temp == fullMark[j]) {
                students[i].solved++;
            }
            if (temp >= 0) {
                students[i].total += temp;
                students[i].flag = true;
            }
        }
    }
    sort(students.begin(), students.end(), cmp);

    students[0].rank = 1;
    for (int i = 1; i < n; i++) {
        students[i].rank = students[i].total == students[i - 1].total ? students[i - 1].rank : i + 1;
    }

    for (int i = 0; i < n; i++) {
        if (!students[i].flag) {
            continue;
        }
        printf("%d %05d %d", students[i].rank, students[i].id, students[i].total);
        for (int j = 0; j < k; j++) {
            if (students[i].score[j] == -1) {
                printf(" 0");
            } else if (students[i].score[j] == -2){
                printf(" -");
            } else {
                printf(" %d", students[i].score[j]);
            }
        }
        cout << endl;
    }
    return 0;
}
