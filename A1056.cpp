/*
 * 1. 本题在于练习queue的使用
 * 2. 有一个技巧，排名与组数有关
 * 3. 像这种一轮一轮的比赛，使用queue很方便
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Mouse {
    int rank;
    int weight;
};

int main() {
    int Np, Ng, index;
    cin >> Np >> Ng;
    vector<Mouse> mice(Np);
    queue<int> q;

    for (int i = 0; i < Np; i++) {
        cin >> mice[i].weight;
    }

    for (int i = 0; i < Np; i++) {
        cin >> index;
        q.push(index);
    }

    while (q.size() != 1) {
        int currentNp = q.size();
        int group = (currentNp + Ng - 1) / Ng;

        for (int i = 1; i <= group; i++) {
            int maxIndex = 0, maxWeight = 0;
            for (int j = 0; j < Ng; j++) {
                if (((i - 1) * Ng + j) == currentNp) {
                    break;
                } else {
                    mice[q.front()].rank = group + 1;
                    if (mice[q.front()].weight > maxWeight) {
                        maxIndex = q.front();
                        maxWeight = mice[q.front()].weight;
                    }
                }
                q.pop();
            }
            q.push(maxIndex);
        }
    }
    mice[q.front()].rank = 1;

    for (int i = 0; i < mice.size(); i++) {
        if (i != 0) {
            cout << " ";
        }
        cout << mice[i].rank;
    }
    return 0;
}
