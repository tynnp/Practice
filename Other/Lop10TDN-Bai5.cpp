#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    double a, b, res;
    cin >> a >> b;
    
    res = (a + b)/2;
    cout << res << endl;
    
    if (res >= 5) cout << "QUA_MON";
    else cout << "ROT_MON";

    return 0;
}