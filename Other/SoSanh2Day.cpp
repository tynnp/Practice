#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

vector<int> chuoiThanhVector(string str) {
    vector<int> res;
    stringstream ss(str);
    string tmp;

    while (getline(ss, tmp, ',')) 
        res.push_back(stoi(tmp));

    return res;
}

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    vector<int> vt1 = chuoiThanhVector(s1);
    vector<int> vt2 = chuoiThanhVector(s2);

    int soNhoNhat = 10e6;
    bool check = false;

    for (int x : vt1) {
        if (find(vt2.begin(), vt2.end(), x) == vt2.end()) {
            soNhoNhat = min(soNhoNhat, x);
            check = true;
        }
    }


    set<int> phanTuChung;
    for (int x : vt1) 
        if (find(vt2.begin(), vt2.end(), x) != vt2.end()) 
            phanTuChung.insert(x);
    
    if (check) cout << soNhoNhat << endl;
    else cout << "khong co" << endl;

    if (!phanTuChung.empty()) {
        cout << phanTuChung.size() << endl;
        for (auto it = phanTuChung.begin(); it != phanTuChung.end(); it++) {
            cout << *it;
            if (++it != phanTuChung.end()) cout << ',';
            it--;
        }   
        cout << endl;
    } else cout << "khong co";

    return 0;
}