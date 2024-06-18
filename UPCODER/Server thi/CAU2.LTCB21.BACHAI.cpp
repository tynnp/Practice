#include <bits/stdc++.h>
using namespace std;

struct pt {
    int a, b, c;
    
    int tongHeSo() {
        return a + b + c;
    }
    
    bool operator > (pt other) {
        if (this->tongHeSo() > other.tongHeSo()) return true;
        if (this->tongHeSo() == other.tongHeSo() && a > other.a) return true;
        if (this->tongHeSo() == other.tongHeSo() && a == other.a) return b > other.b;
        return false;
    }
    
    friend istream &operator >> (istream &in, pt &p) {
        in >> p.a >> p.b >> p.c;
        return in;
    }
    
    friend ostream &operator << (ostream &out, pt p) {
        if (p.a != 1) out << p.a;
        out << "x^2";
        
        if (p.b != 0) {
            cout << (p.b < 0 ? '-' : '+');
            if (abs(p.b) != 1) out << abs(p.b);
            out << 'x';
        }
            
        if (p.c != 0) {
            cout << (p.c < 0 ? '-' : '+');
            cout << abs(p.c);
        }
        
        out << "=0";
        return out;
    }
};

int main() {
    int n;
    cin >> n;
    
    pt list[n];
    for (auto &x : list) cin >> x;
    
    pt ans = list[0];
    for (auto x : list)
        if (ans > x)
            ans = x;
    
    cout << ans;
    return 0;
}