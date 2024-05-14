#include <bits/stdc++.h>
using namespace std;

int main() {
    string tmp;
    
    while (cin >> tmp) {
        size_t pos = tmp.find("@gmail.com");
        if (pos != string::npos) cout << tmp << endl;
    }
    
    return 0;
}