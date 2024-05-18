#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);
    
    int count = 0;
    size_t pos = b.find(a);
    while (pos != string::npos) {
        ++count;
        pos = b.find(a, pos + a.length()-1);
    }
    
    cout << count << endl;
    
    return 0;
}
