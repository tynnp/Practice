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
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    
    char c;
    int biTrung = 0;
    string str;
    vector<string> hoTen, ten, gmail;
    
    fin >> c;
    fin.ignore();
    while (getline(fin, str)) {
        for (char &s : str)
            s = tolower(s);
        hoTen.push_back(str);
    }
    
    for (string s : hoTen) {
        string res, tmp = taoTen(s);
        int kyTuTrung = count(s.begin(), s.end(), tolower(c));
        int soLuong = count(ten.begin(), ten.end(), tmp);
        
        res = to_string(kyTuTrung) + "-" + tmp;
        if (soLuong == 0)
            res += "@gmail.com\n";
        else {
            biTrung += soLuong == 1 ? 2 : 1;
            res += to_string(soLuong+1) + "@gmail.com\n";
        }
        
        gmail.push_back(res);
        ten.push_back(tmp);
    }
    
    for (string s : gmail) fout << s;
    fout << biTrung;
    
    fin.close();
    fout.close();
    return 0;
}