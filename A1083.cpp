/*
 * 1. 本题比较简单
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    char name[15];
    char ID[15];
    int grade;
};

bool cmp(Student s1, Student s2) {
    return s1.grade > s2.grade;
}

int main() {
    bool flag = false;
    int n, grade1, grade2;
    cin >> n;
    vector<Student> students(n);

    for (int i = 0; i < n; i++) {
        scanf("%s %s %d", students[i].name, students[i].ID, &students[i].grade);
    }
    scanf("%d %d", &grade1, &grade2);

    sort(students.begin(), students.end(), cmp);

    for (auto e : students) {
        if (e.grade >= grade1 && e.grade <= grade2) {
            printf("%s %s\n", e.name, e.ID);
            flag = true;
        }
    }

    if (!flag) {
        cout << "NONE";
    }

    return 0;
}
