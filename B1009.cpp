/*
 * 1. 反转的事情，用stack实现很方便, stack.pop() stack.push() stack.top()
 * 2. getline(cin, s); 读取一行，要不然只读取一个单词
 * 3. 在输入字符串后面加" "， 使程序更加统一
 * 4. 更简单的方法是使用cin >> s, 读取一个单词的特性，来收集单词
 * 5. cin >> s 除非到来1. End of file 2. Invalid input, 不然不会停止
 */

#include <iostream>
#include <stack>
using namespace std;

int main() {
    bool sign = false;
    string word;
    stack<string> st;

    while (cin >> word) {
        st.push(word);
    }

    while (!st.empty()) {
        if (sign) {
            cout << " ";
        }
        sign = true;
        cout << st.top();
        st.pop();
    }
}

/*
#include <iostream>
#include <stack>
using namespace std;

int main() {
    bool sign = false;
    string s;
    string temp;
    stack<string> st;
    getline(cin, s);
    s.append(" ");


    for (auto e : s) {
        if (e != ' ') {
            temp.append(1, e);
        } else {
            st.push(temp);
            temp = "";
        }
    }

    while (!st.empty()) {
        if (sign) {
            cout << " ";
        }
        sign = true;
        cout << st.top();
        st.pop();
    }
    return 0;
}
 */
