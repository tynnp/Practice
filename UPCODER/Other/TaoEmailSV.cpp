#include <bits/stdc++.h>
using namespace std;

string taoTen(string str) {
    string tmp, res("");
    stringstream ss(str);
    vector<string> v;
    
    while (ss >> tmp) 
        v.push_back(tmp);
    
    res = v.back();
    v.pop_back();
    
    for (string x : v)
        res += x[0];
    
    return res;
}

int main() {
    char c;
    string str;
    vector<string> hoTen, ten, gmail;
    
    cin >> c;
    cin.ignore();
    while (getline(cin, str)) {
        for (char &s : str)
            s = tolower(s);
        hoTen.push_back(str);
    }
    
    for (string s : hoTen) {
        string res, tmp = taoTen(s);
        int kyTuTrung = count(s.begin(), s.end(), tolower(c));
        int soLuong = count(ten.begin(), ten.end(), tmp);
        
        res = tmp;
        if (soLuong == 0)
            res += "@gmail.com";
        else 
            res += to_string(soLuong+1) + "@gmail.com";
        
        gmail.push_back(res);
        ten.push_back(tmp);
    }
    
    for (int i = 0; i < gmail.size(); i++) {
        if (i > 0) cout << endl;
        cout << gmail[i];
    }

    return 0;
}