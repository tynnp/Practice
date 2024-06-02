#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test; 
    string str; 
    cin >> test >> str;

    while (test--) {
        int cnt = 0;
        string strc; cin >> strc;

        int m = strc.find(str);
        while (m != -1) 
            m = strc.find(str, m + str.length() - 1),
            cnt++;
            
        cout << cnt << endl;
    }
    
    return 0;
}