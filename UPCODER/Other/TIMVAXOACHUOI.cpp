#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    
    size_t pos = a.find(b);
    while (pos != string::npos) {
        a.erase(pos, b.size());
        pos = a.find(b, 0);
    }
    
    pos = a.find("  ");
    if (pos != string::npos) a.erase(pos, 1);
    
    cout << a;
    return 0;
}