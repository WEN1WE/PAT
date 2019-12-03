/*
 * 1. 本题模拟栈，但写的时候逻辑很混乱
 * 2. 要抓住栈满，什么时候元素进栈
 */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int M, N, K;
    cin >> M >> N >> K;

    for (int i = 0; i < K; i++) {
        vector<int> v(N);
        stack<int> s;
        int current = 1;
        for (int j = 0; j < N; j++) {
            cin >> v[j];
        }
        bool flag = true;
        for (int j = 0; j < N; j++) {
            while (true) {
                if (s.empty() || s.top() != v[j]) {
                    s.push(current);
                    current++;
                    if (s.size() > M) {
                        flag = false;
                        break;
                    }
                } else {
                    s.pop();
                    break;
                }
            }
            if (!flag) {
                break;
            }
        }

        if (!flag || !s.empty()) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
    return 0;
}




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
