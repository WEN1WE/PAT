/*
 * 1. 由于题目n比较大，肯定是效率问题
 * 2. 所以只可以对前面的k个数进行sort
 * 3. 主要问题是确定index是否已经进入，以及没有进入时怎么办
 */


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 50010;
struct Item {
    int index;
    int count = 0;
};
vector<Item> items(MAX);

bool cmp(int p1, int p2) {
    if (items[p1].count == items[p2].count) {
        return items[p1].count + items[p1].index < items[p2].count + items[p2].index;
    } else {
        return items[p1].count > items[p2].count;
    }
}

int main() {
    int n, k, index;
    scanf("%d %d", &n, &k);
    bool table[MAX] = {false};
    vector<int> topIndex(k);
    
    for (int i = 1; i <= n; i++) {
        items[i].index = i;
    }
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &index);
        if (i != 0) {
            printf("%d:", index);
            for (auto e : topIndex) {
                if (items[e].count != 0) {
                    printf(" %d", e);
                } else {
                    break;
                }
            }
            printf("\n");
        }
        items[index].count++;
        if (!table[index] && cmp(index, topIndex[k -1])) {
            table[index] = true;
            table[topIndex[k - 1]] = false;
            topIndex[k - 1] = index;
            sort(topIndex.begin(), topIndex.end(), cmp);
        } else if (table[index]) {
            sort(topIndex.begin(), topIndex.end(), cmp);
        }
    }
    return 0;
}


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int MAX = 50010;
vector<int> cnt(MAX);

bool cmp(int id1, int id2) {
    if (cnt[id1] != cnt[id2]) {
        return cnt[id1] > cnt[id2];
    } else {
        return id1 < id2;
    }
}

int main() {
    int N, K, indices;
    scanf("%d %d", &N, &K);
    vector<bool> isIn(MAX);
    vector<int>  recommend(K);
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &indices);
        if (i != 0) {
            printf("%d:", indices);
            for (int e : recommend) {
                if (cnt[e] == 0) {
                    break;
                }
                printf(" %d", e);
            }
            printf("\n");
        }
        cnt[indices]++;
        if (isIn[indices]) {
            sort(recommend.begin(), recommend.end(), cmp);
        } else {
            if (cmp(indices, recommend[K - 1])) {
                isIn[indices] = true;
                isIn[recommend[K - 1]] = false;
                recommend[K - 1] = indices;
                sort(recommend.begin(), recommend.end(), cmp);
            }
        }
        
    }
    return 0;
}
