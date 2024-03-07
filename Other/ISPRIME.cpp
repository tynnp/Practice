#include <iostream>
#include <cmath>
using namespace std;

bool nguyenTo(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) 
        if (num % i == 0) return false;
    return true;
}

bool chia3(string s) {
    int tong = 0;
    for (char c : s)
        tong += (c - '0');
    return tong % 3 == 0;
}

bool check(string s) {
    int len = s.size();
    if (len > 1) {
        int haiSoCuoi = (s[len - 2] - '0') * 10 + (s[len - 1] - '0');
        if (haiSoCuoi % 2 != 0 && haiSoCuoi % 5 != 0) {
            if (chia3(s)) return false;
            else return true;
        } else return false;
        
    } else {
        int num = s[0] - '0';
        if (num < 2) return false;
        else return nguyenTo(num);
    }
}

int main() {
    int n;
    string v;
    cin >> n;
    
    while (n--) {
        cin >> v;
        if (check(v)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}