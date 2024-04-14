#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

struct ThongTin {
    int sothuTu;
    string tenSinhVien;
    string maSoSinhVien;
    
    ThongTin() {}
    ThongTin(string tmp) {
        stringstream ss(tmp);
        vector<string> v;
        
        while (ss >> tmp)
            v.push_back(tmp);
        
        sothuTu = stoi(v.front());
        v.erase(v.begin());
        
        maSoSinhVien = v.back();
        v.pop_back();
        
        for (string x : v) 
            tenSinhVien += x + " ";
    }
    
    friend ostream &operator << (ostream &cout, ThongTin obj) {
        cout << "STT: " << obj.sothuTu << endl;
        cout << "Ho va ten: " << obj.tenSinhVien << endl;
        cout << "MSSV: " << obj.maSoSinhVien << endl;
    }
};

int main() {
    vector<ThongTin> list;
    string tmp;
    
    while (getline(cin, tmp))  
        list.push_back(ThongTin(tmp));
        
    sort(list.begin(), list.end(), [] (ThongTin a, ThongTin b) {
        return a.sothuTu < b.sothuTu;
    });
    
    for (auto x : list)
        cout << x << endl;
    return 0;
}