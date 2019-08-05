/*
 * 1. vector v的大小: v.size()
 * 2. copy vector 直接用 = ，产生一份全新的
 * 3. 自己原来的程序太长，结构体没有设计好，应该将分数合并处理
 * 4. 由于要进行ID的搜索，所以建立一个二维数组，以ID为下标，有利于查找, 但clion里面没法通过
 * 5. 没有弄明白并列排名：100 99 99 94 排名为 1 2 2 4
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Student {
    string ID;
    int grades[4];
    int rankRecord[4];
};
int METHOD;

bool cmp(Student student1, Student student2) {
    return student1.grades[METHOD] > student2.grades[METHOD];
}

int findStudent(vector<Student> students, string ID) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].ID == ID) {
            return i;
        }
    }
    return 3000;
}

int main() {
    int n, m;
    string ID;
    string table = "ACME";
    cin >> n >> m;
    vector<Student> students(n);

    for (int i = 0; i < n; i++) {
        cin >> students[i].ID >> students[i].grades[1] >> students[i].grades[2] >> students[i].grades[3];
        students[i].grades[0] = students[i].grades[1] + students[i].grades[2] + students[i].grades[3];
    }

    for (int i = 0; i < 4; i++) {
        METHOD = i;
        sort(students.begin(), students.end(), cmp);
        students[0].rankRecord[i] = 1;
        for (int j = 1; j < n; j++) {
            if (students[j].grades[i] != students[j - 1].grades[i]) {
                students[j].rankRecord[i] = j + 1;
            } else {
                students[j].rankRecord[i] = students[j - 1].rankRecord[i];
            }
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> ID;
        int bestRank = 2001;
        char course = 0;
        int index = findStudent(students, ID);
        if (index == 3000) {
            cout << "N/A" << endl;
            continue;
        } else {
            for(int j = 0; j < 4; j++) {
                if (students[index].rankRecord[j] < bestRank) {
                    bestRank = students[index].rankRecord[j];
                    course = table[j];
                }
            }
            cout << bestRank << " " << course << endl;
        }
    }
    return 0;
}


/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int METHOD;

struct Student {
    string ID;
    int C;
    int M;
    int E;
    int S;
};

bool cmp(Student student1, Student student2) {
    if (METHOD == 0) {
        return student1.S > student2.S;
    } else if (METHOD == 1) {
        return student1.C > student2.C;
    } else if (METHOD == 2) {
        return student1.M > student2.M;
    } else {
        return student1.E > student2.E;
    }
}

bool isIn(vector<Student> students, string ID) {
    for (auto student : students) {
        if (student.ID == ID) {
            return true;
        }
    }
    return false;
}

int getRank(vector<Student> students, string ID) {
    if (students[0].ID == ID) {
        return 1;
    }
    int count = 1;
    if (METHOD == 0) {
        for (int i = 1; i < students.size(); i++) {
            if (students[i].S != students[i - 1].S) {
                count++;
            }
            if (students[i].ID == ID) {
                return count;
            }
        }
    } else if (METHOD == 1) {
        for (int i = 1; i < students.size(); i++) {
            if (students[i].C != students[i - 1].C) {
                count++;
            }
            if (students[i].ID == ID) {
                return count;
            }
        }
    } else if (METHOD == 2) {
        for (int i = 1; i < students.size(); i++) {
            if (students[i].M != students[i - 1].M) {
                count++;
            }
            if (students[i].ID == ID) {
                return count;
            }
        }
    } else {
        for (int i = 1; i < students.size(); i++) {
            if (students[i].E != students[i - 1].E) {
                count++;
            }
            if (students[i].ID == ID) {
                return count;
            }
        }
    }
}

int main() {
    char method = 0;
    int bestRank = 2001;
    int n, m;
    int temp;
    string table = "ACME";

    cin >> n >> m;
    vector<Student> students(n);
    vector<vector<Student>> studentsRank(4);
    string checks[m];

    for (int i = 0; i < n; i++) {
        cin >> students[i].ID >> students[i].C >> students[i].M >> students[i].E;
        students[i].S = students[i].C + students[i].M + students[i].E;
    }

    for (int i = 0; i < m; i++) {
        cin >> checks[i];
    }

    for (int i = 0; i < 4; i++) {
        METHOD = i;
        sort(students.begin(), students.end(), cmp);
        studentsRank[i] = students;
    }


    for (int i = 0; i < m; i++) {
        if (!isIn(students, checks[i])) {
            cout << "N/A" << endl;
        } else {
            for (int j = 0; j < 4; j++) {
                METHOD = j;
                temp = getRank(studentsRank[j], checks[i]);
                if (temp < bestRank) {
                    bestRank = temp;
                    method = table[j];
                }
            }
            cout << bestRank << " " << method << endl;
        }
        bestRank = 2001;
    }

    return 0;
}

*/
/*
5 1
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
999999
 */
