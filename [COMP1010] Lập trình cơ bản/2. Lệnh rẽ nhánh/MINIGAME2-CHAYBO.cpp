#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, time; 
    cin >> a >> b >> c >> time;
    int res = a + b + c;
    res = time % res;

    if (res == 0 || res == a + b + c) cout << "A";
    else if (res == a) cout << "B";
    else if (res == a + b) cout << "C";
    else if (res > 0 && res < a) cout << "AB";
    else if (res > a && res < a + b) cout << "BC";
    else if (res > a + b && res < a + b + c) cout << "CA";

    return 0;
}