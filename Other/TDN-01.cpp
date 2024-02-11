#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int ngay[] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int nam, thang;
    cin >> nam >> thang;
    
    ngay[2] = (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0) ? 29 : 28);
    cout << ngay[thang];
    return 0;
}