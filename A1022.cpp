/*
 * 1. 本题使用set很方便，set内部是自动排序的
 * 2. 传值传引用，不然会超时
 * 3. scanf("%d: ", &type);  // scanf 获取信息的方法
 * 4. 一行中，分空格读取字符串，本题方法很特别
 * 5. 本题读入int 的过程中，可能前面的0被去掉，要注意输出的格式
 * 6. 本题使用set<string> 也可以
 */

#include <iostream>
#include <map>
#include <set>
using namespace std;

void query(map<string, set<string>> & mp, string & s) {
    if (mp.find(s) != mp.end()) {
        for (auto e : mp[s]) {
            cout << e << endl;
        }
    } else {
        printf("Not Found\n");
    }
}

int main() {
    int n, m, type;
    string id;
    string temp;
    string title, author, keyword, publisher, year;
    map<string, set<string>> mpTitle, mpAuthor, mpKeyword, mpPublisher, mpYear;
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        char c;
        getline(cin, id);

        getline(cin, title);
        mpTitle[title].insert(id);

        getline(cin, author);
        mpAuthor[author].insert(id);

        while (cin >> keyword) {
            mpKeyword[keyword].insert(id);
            c = getchar();
            if (c == '\n') {
                break;
            }
        }

        getline(cin, publisher);
        mpPublisher[publisher].insert(id);

        getline(cin, year);
        mpYear[year].insert(id);
    }

    scanf("%d", &m);
    getchar();

    for (int i = 0; i < m; i++) {
        scanf("%d: ", &type);
        getline(cin, temp);
        printf("%d: %s\n", type, temp.c_str());
        if (type == 1) {
            query(mpTitle, temp);
        } else if (type == 2) {
            query(mpAuthor, temp);
        } else if (type == 3) {
            query(mpKeyword, temp);
        } else if (type == 4) {
            query(mpPublisher, temp);
        } else {
            query(mpYear, temp);
        }
    }
    return 0;
}



#include <iostream>
#include <map>
#include <set>
using namespace std;

void query(map<string, set<int>> & mp, string & s) {
    if (mp.find(s) != mp.end()) {
        for (auto e : mp[s]) {
            printf("%07d\n", e);
        }
    } else {
        printf("Not Found\n");
    }
}

int main() {
    int n, m, id, type;
    string temp;
    string title, author, keyword, publisher, year;
    map<string, set<int>> mpTitle, mpAuthor, mpKeyword, mpPublisher, mpYear;
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        char c;
        scanf("%d", &id);
        getchar();

        getline(cin, title);
        mpTitle[title].insert(id);

        getline(cin, author);
        mpAuthor[author].insert(id);

        while (cin >> keyword) {
            mpKeyword[keyword].insert(id);
            c = getchar();
            if (c == '\n') {
                break;
            }
        }

        getline(cin, publisher);
        mpPublisher[publisher].insert(id);

        getline(cin, year);
        mpYear[year].insert(id);
    }

    scanf("%d", &m);
    getchar();

    for (int i = 0; i < m; i++) {
        scanf("%d: ", &type);
        getline(cin, temp);
        printf("%d: %s\n", type, temp.c_str());
        if (type == 1) {
            query(mpTitle, temp);
        } else if (type == 2) {
            query(mpAuthor, temp);
        } else if (type == 3) {
            query(mpKeyword, temp);
        } else if (type == 4) {
            query(mpPublisher, temp);
        } else {
            query(mpYear, temp);
        }
    }
    return 0;
}
