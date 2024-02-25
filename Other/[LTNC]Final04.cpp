#include <iostream>
using namespace std;

string kiemTra(string str) {
    if (str.size() != 10) return "Khong hop le";
    string st1 = str.substr(0, 2), rst1 = str.substr(2); 
    string st2 = str.substr(0, 3), rst2 = str.substr(3);
    string st3 = str.substr(0, 4), rst3 = str.substr(4);
    if (st1 == "04") return "Ha Noi - " + rst1;
    if (st1 == "08") return "TPHCM - " + rst1;
    if (st2 == "059") return "Gia Lai - " + rst2;
    if (st2 == "061") return "Dong Nai - " + rst2;
    if (st3 == "0511") return "Da Nang - " + rst3;
    if (st3 == "0710") return "Can Tho - " + rst3;
    return "Khong hop le";
}

int main() {
    string str; 
    cin >> str;
    cout << kiemTra(str);
    return 0;
}