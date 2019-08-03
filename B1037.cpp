/*
 * 1. scanf("%lld", long long)
 */

#include <iostream>
using namespace std;

long long toKnut(long long Galleon, long long Sickle, long long Knut) {
    return Galleon * 493 + Sickle * 29 + Knut;
}

int main() {
    long long Galleon = 0, Sickle = 0, Knut = 0;
    long long Galleon1, Sickle1, Knut1;
    long long Galleon2, Sickle2, Knut2;
    scanf("%lld.%lld.%lld %lld.%lld.%lld", &Galleon1, &Sickle1, &Knut1, &Galleon2, &Sickle2, &Knut2);

    Knut = toKnut(Galleon2, Sickle2, Knut2) - toKnut(Galleon1, Sickle1, Knut1);
    if (Knut < 0) {
        cout << "-";
        Knut = -Knut;
    }
    Galleon = Knut / 493;
    Knut = Knut % 493;
    Sickle = Knut / 29;
    Knut = Knut % 29;
    cout << Galleon << "." << Sickle << "." << Knut;
    return 0;
}
