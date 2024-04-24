#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    while (n--) {
        string s;
        cin >> s;
        
        int h = s.size()/2;
        bool sq(true);
        
        for (int i = 0; i < h; i++)
            if (s[i] != s[h+i]) {
                sq = false;
                break;
            }
        
        if (s.size() & 1) cout << "NO" << endl;
        else cout << (sq ? "YES" : "NO") << endl;
    }
    
    return 0;
}