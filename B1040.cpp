#include <iostream>
using namespace std;

const int MAXLENGTH = 100010;

int main() {
    long long total = 0;
    string s;
    cin >> s;
    int leftP[MAXLENGTH] = {0};
    int rightT[MAXLENGTH] = {0};

    for (int i = 0; i < s.length(); i++) {
        if (i > 0) {
            leftP[i] = leftP[i - 1];
        }
        if (s[i] == 'P') {
            leftP[i]++;
        }
    }

    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == 'T') {
            rightT[i]++;
        }
        if (i > 0) {
            rightT[i - 1] = rightT[i];
        }
    }

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'A') {
            total += leftP[i] * rightT[i];
        }
    }
    cout << total % 1000000007;

    return 0;
}
