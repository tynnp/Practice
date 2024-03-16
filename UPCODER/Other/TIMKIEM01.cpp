#include <iostream>
#include <vector>
using namespace std;

istream& operator >> (istream& in, pair<int, int>& p) {
    in >> p.first >> p.second;
}

ostream& operator << (ostream& out, pair<int, int> p) {
    out << p.first << " " << p.second;
}

int check(pair<int, int> p) {
    return abs(p.first - p.second);
}

int check2(pair<int, int> p) {
    return p.first + p.second;
}

int main() {
    int n; cin >> n;
    pair<int, int> max = {0, 0};
    vector<pair<int, int>> vt;
    vector<pair<int, int>> res;

    while (n--) {
        pair<int, int> p; 
        cin >> p; 
        vt.push_back(p);
        if (check(max) < check(p)) max = p;
    }

    for (auto x : vt) if (check(x) == check(max)) res.push_back(x);
    for (auto x : res) if(check2(max) < check2(x)) max = x;
    
    cout << max;
    return 0;
}   