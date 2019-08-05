/*
 * 1. 当vector 传入函数时，传引用，才能改变原来的值
 * 2. 使用char[] 来接收字符串，printf 时就不用使用 myString.c_str();
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int FINALORLOCAL;

struct Student {
    string id;
    int score;
    int locationNumber;
    int rank[2];
};

void caclRank(vector<Student> & students, int n) {
    students[0].rank[FINALORLOCAL] = 1;
    for (int i = 1; i < n; i++) {
        if (students[i].score != students[i - 1].score) {
            students[i].rank[FINALORLOCAL] = i + 1;
        } else {
            students[i].rank[FINALORLOCAL] = students[i - 1].rank[FINALORLOCAL];
        }
    }
}

bool cmp(Student s1, Student s2) {
    if (s1.score != s2.score) {
        return s1.score > s2.score;
    }
    return s1.id < s2.id;
}

int main() {
    int n;
    cin >> n;
    int k[n];
    int count = 0;
    vector<Student> students(30000);

    for (int i = 0; i < n; i++) {
        vector<Student> localStudents(300);
        cin >> k[i];
        for (int j = 0; j < k[i]; j++) {
            cin >> localStudents[j].id >> localStudents[j].score;
            localStudents[j].locationNumber = i + 1;
        }
        sort(localStudents.begin(), localStudents.end(), cmp);
        FINALORLOCAL = 1;
        caclRank(localStudents, k[i]);

        for (int j = 0; j < k[i]; j++) {
            students[count++] = localStudents[j];
        }
    }

    sort(students.begin(), students.end(), cmp);
    FINALORLOCAL = 0;
    caclRank(students, count);

    cout << count << endl;
    for (int i = 0; i < count; i++) {
        printf("%s %d %d %d\n", students[i].id.c_str(), students[i].rank[0], students[i].locationNumber, students[i].rank[1]);
    }
    return 0;
}
