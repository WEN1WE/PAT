/*
 * 1. 先分类，然后使用两个指针填写数字
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    string name;
    int high;
};

bool cmp (Student & s1, Student & s2) {
    return s1.high == s2.high ? s1.name < s2.name : s1.high > s2.high;
}

void place(int start, int end, vector<Student> & students, vector<Student> & result) {
    int p = start;
    int central = (end - start + 1) / 2 + start;
    int left = central - 1;
    int right = central + 1;
    bool flag = true;
    
    result[central - 1] = students[p - 1];
    p++;
    
    while (p <= end) {
        if (left >= start && flag) {
            result[left - 1] = students[p - 1];
            left--;
            flag = !flag;
            p++;
        } else if (right <= end && !flag) {
            result[right - 1] = students[p - 1];
            right++;
            flag = !flag;
            p++;
        }
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int eachRow = n / k;
    int rearRow = eachRow + n % k;
    vector<Student> students(n);
    vector<Student> result(n);
    for (int i = 0; i < n; i++) {
        cin >> students[i].name >> students[i].high;
    }
    sort(students.begin(), students.end(), cmp);
    
    int start = 1, end = rearRow;
    
    for (int i = 0; i < k; i++) {
        place(start, end, students, result);
        start = end + 1;
        end = end + eachRow;
    }
    
    for (int i = 0; i < k; i++) {
        if (i == 0) {
            for (int j = 0; j < rearRow; j++) {
                if (j != 0) {
                    printf(" ");
                }
                printf("%s", result[j].name.c_str());
            }
            printf("\n");
        } else {
            for (int j = 0; j < eachRow; j++) {
                if (j != 0) {
                    printf(" ");
                }
                printf("%s", result[rearRow + (i - 1) * eachRow + j].name.c_str());
            }
            printf("\n");
        }
    }
    
    return 0;
}
