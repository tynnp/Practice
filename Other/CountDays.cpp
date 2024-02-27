#include <iostream>
#define ll long long
using namespace std;

bool nam_nhuan(ll n) {
    return (n % 400 == 0 || (n%4 == 0 && n%100 != 0));
}
 
ll _nam(ll n) {
    int ngay;
    if (n == 0) return 0;
    else if (n == 1) return 365;
    else if (nam_nhuan(n)) ngay = 366;
    else ngay = 365;
    return ngay + _nam(n - 1);
}

ll _thang(ll thang, ll nam) {
    int ngay;
    switch (thang) {
        case 1: return 0; break;
        case 3: ngay = 31; break;
        case 4: ngay = 30; break;
        case 5: ngay = 31; break;
        case 6: ngay = 30; break;
        case 7: ngay = 31; break;
        case 8: ngay = 31; break;
        case 9: ngay = 30; break;
        case 10: ngay = 31; break;
        case 11: ngay = 30; break;
        case 12: ngay = 31; break;
        default: 
            if (nam_nhuan(nam)) ngay = 29;
            else ngay = 28;
    } 
    return ngay + _thang(thang - 1, nam);
}

int main() {
    int ngay, thang, nam;
    char ch1, ch2;
    cin >> ngay >> ch1 >> thang >> ch2 >> nam;
    if (ngay < 1 || ngay > 31 || thang < 1 || thang > 12 || nam < 1) 
        cout << "None";
    else if (ngay == 29 && thang == 2 && !nam_nhuan(nam))
        cout << "None";
    else if (ngay == 31 && thang != 1 && thang != 3 && thang != 5 && thang != 7 && thang != 8 && thang != 10 && thang != 12)
        cout << "None";
    else 
        cout << ngay + _thang(thang, nam) + _nam(nam - 1) - 1;
    return 0;
}