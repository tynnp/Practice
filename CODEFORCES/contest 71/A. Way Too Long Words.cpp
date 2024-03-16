#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        string tmp;
        cin >> tmp;
        if (tmp.length() >= 11) 
            cout << tmp[0] << tmp.length()-2 << tmp[tmp.length()-1];
        else cout << tmp;
        cout << endl;
    }

    return 0;
}