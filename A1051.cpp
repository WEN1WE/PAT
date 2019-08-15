/*
 * 1. 本题模拟栈，但写的时候逻辑很混乱
 * 2. 要抓住栈满，什么时候元素进栈
 */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool judge(int size, int n, vector<int> & sequence) {
    int index = 0, current = 1;
    stack<int> st;

    while (true) {
        if (!st.empty() && st.top() == sequence[index]) {
            st.pop();
            index++;
        } else {
            if (current > n) {
                break;
            }
            st.push(current);

            if (st.size() > size) {
                return false;
            }

            current++;
        }
    }
    return st.empty();
}

int main() {
    int size, n, k;
    cin >> size >> n >> k;
    vector<int> sequence(n);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> sequence[j];
        }
        if (judge(size, n, sequence)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}

/*
5 7 1
7 6 5 4 3 2 1
 */
