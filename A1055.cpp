/*
 * 1. round 可以对double 进行四舍五入
 * 2. char name[10] 读入一个字符串，末尾有'\0', printf will print all characters starting from given address until it finds '\0'.
 * 3. strcmp 字符数组的比较, 但要包含头文件 #include <cstring>
 * 4. 使用cout cin 会超时
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

struct Person {
    char name[10];
    int age;
    int netWorth;
};

bool cmp(Person p1, Person p2) {
    if (p1.netWorth == p2.netWorth) {
        return p1.age != p2.age ? p1.age < p2.age : strcmp(p1.name, p2.name) < 0;
    } else {
        return p1.netWorth > p2.netWorth;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<Person> billionaires(n);

    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", billionaires[i].name, &billionaires[i].age, &billionaires[i].netWorth);
        //cin >> billionaires[i].name >> billionaires[i].age >> billionaires[i].netWorth;
    }
    sort(billionaires.begin(), billionaires.end(), cmp);

    for (int i = 0; i < k; i++) {
        printf("Case #%d:\n", i + 1);
        int maxNumber, ageMin, ageMax, count = 0;
        scanf("%d %d %d", &maxNumber, &ageMin, &ageMax);

        for (auto e : billionaires) {
            if (count >= maxNumber) {
                break;
            }

            if (e.age >= ageMin && e.age <= ageMax) {
                printf("%s %d %d\n", e.name, e.age, e.netWorth);
                count++;
            }
        }
        if (count == 0) {
            printf("None\n");
        }
    }
    return 0;
}
