#include <iostream>
#define ll long long
using namespace std;

ll t, l, r;

int main() {
    cin >> t;

    while (t--) {
        cin >> l >> r;
        l = l - 1;
        ll l4 = l / 4 + 1;
        ll l7 = l / 7 + 1;
        ll l11 = l / 11 + 1;
        ll l47 = l / 28 + 1;
        ll l411 = l / 44 + 1;
        ll l711 = l / 77 + 1;
        ll l308 = l / 308 + 1;

        ll r4 = r / 4 + 1;
        ll r7 = r / 7 + 1;
        ll r11 = r / 11 + 1;
        ll r47 = r / 28 + 1;
        ll r411 = r / 44 + 1;
        ll r711 = r / 77 + 1;
        ll r308 = r / 308 + 1;

        ll lll = l4 + l7 + l11 - (l47 + l411 + l711) + l308;
        ll rrr = r4 + r7 + r11 - (r47 + r411 + r711) + r308;

        if (l + 1 == 0) cout << rrr - lll + 1 << "\n";
        else cout << rrr - lll << "\n";
    }
    
    return 0;
}
