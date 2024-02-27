#include <iostream>
#include <iomanip>
using namespace std;
 
struct DATE {
    int d, m, y;
};

void nhapDate(DATE &date) {
    cin >> date.d >> date.m >> date.y;
}

void xuatDate(DATE date) {
    cout << setw(2) << setfill('0') << date.d <<"/";
    cout << setw(2) << setfill('0') << date.m <<"/";
    cout << setw(4) << setfill('0') << date.y;
    cout<< endl;
}

struct TIME {
    int h, m;
};

void nhapTime(TIME &t) {
    cin >> t.h >> t.m;
}

void xuatTime(TIME t) {
    if(t.m == 60){
        t.h++;
        t.m = 0;
    }
    cout << t.h<<":";
    cout << setw(2) << setfill('0') << t.m;
    cout << endl;
}

struct CB {
    string machuyenbay;
    DATE date;
    TIME flytime;
    string noidi;
    string noiden;
};

void nhapCB(CB &cb) {
    getline(cin, cb.machuyenbay);
    nhapDate(cb.date);
    nhapTime(cb.flytime);
    cin.ignore();
    getline(cin, cb.noidi);
    getline(cin, cb.noiden);
}

void xuatCB(CB cb) {
    cout << "ma chuyen bay: " << cb.machuyenbay << endl;
    cout << "ngay bay: "; xuatDate(cb.date);
    cout << "gio bay: "; xuatTime(cb.flytime);
    cout << "noi di: " << cb.noidi << endl;
    cout << "noi den: " << cb.noiden << endl;
}

int main(){
    CB cb;
    nhapCB(cb);
    xuatCB(cb);
}