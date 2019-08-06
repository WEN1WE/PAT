/*
 * 1. 读清题目，不懂的单词，根据上下文，猜
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    int id;
    int Ge, Gi;
    int total;
    int rank;
    int preferred[5];
};

struct School {
    int id;
    int quota;
    int size = 0;
    vector<Student> students;
};

bool cmp(Student s1, Student s2) {
    return s1.total == s2.total ? s1.Ge > s2.Ge : s1.total > s2.total;
}

bool cmpID(Student s1, Student s2) {
    return s1.id < s2.id;
}

int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    vector<Student> students(N);
    vector<School> schools(M);

    for (int i = 0; i < M; i++) {
        schools[i].id = i;
        scanf("%d", &schools[i].quota);
    }

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &students[i].Ge, &students[i].Gi);
        students[i].total = students[i].Ge + students[i].Gi;
        for (int j = 0; j < K; j++) {
            scanf("%d", &students[i].preferred[j]);
        }
        students[i].id = i;
    }

    sort(students.begin(), students.end(), cmp);

    students[0].rank = 1;
    for (int i = 1; i < N; i++) {
        if (students[i].total == students[i - 1].total && students[i].Ge == students[i - 1].Ge) {
            students[i].rank = students[i - 1].rank;
        } else {
            students[i].rank = i + 1;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            int id = students[i].preferred[j];
            if ((schools[id].size < schools[id].quota) || (students[i].rank == schools[id].students[schools[id].size - 1].rank)) {
                schools[id].students.push_back(students[i]);
                schools[id].size++;
                break;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        if (schools[i].size != 0) {
            sort(schools[i].students.begin(), schools[i].students.end(), cmpID);
        }
    }

    for (int i = 0; i < M; i++) {
        int flag = false;
        if (schools[i].size != 0) {
            for (auto e : schools[i].students) {
                if (flag) {
                    cout << " ";
                }
                cout << e.id;
                flag = true;
            }
        }
        cout << endl;
    }
    return 0;
}
