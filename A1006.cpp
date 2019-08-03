/*
 * 1. 此题主要对输入进行记录，然后比较
 */

#include <iostream>
using namespace std;

int main() {
    int n;
    string unlockTime = "24:00:00";
    string lockTime = "00:00:00";
    string id, signIn, signOut, unlockId, lockId;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> id >> signIn >> signOut;
        if (signIn < unlockTime) {
            unlockTime = signIn;
            unlockId = id;
        }

        if (signOut > lockTime) {
            lockTime = signOut;
            lockId = id;
        }
    }
    cout << unlockId << " " << lockId << endl;
    return 0;
}
