#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int ngay, thang, nam; 
    cin >> ngay >> thang >> nam;
    if (nam < 1900 || (thang > 12 || thang < 1)) cout << "NO";
    else if ((thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12) && (ngay < 1 || ngay > 31)) cout << "NO";
    else if ((thang == 4 || thang == 6 || thang == 9 || thang == 11) && (ngay < 1 || ngay > 30)) cout << "NO";
    else if ((nam % 400 == 0 || (nam % 4 == 0 && nam % 400 != 0)) && thang == 2 && (ngay < 1 || ngay > 29)) cout << "NO";
    else if (thang == 2 && (ngay < 1 || ngay > 28)) cout << "NO";
    else cout << "YES";
    return 0;
}