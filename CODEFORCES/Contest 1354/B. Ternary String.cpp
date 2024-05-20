#include <bits/stdc++.h>
using namespace std;

int main () {
    int t, res(INT_MAX);
    string s;
    cin >> t;

    while (t--) {
        cin >> s;
        int arr[s.size()+1][4];

        arr[0][1] = arr[0][2] = arr[0][3] = 0;
        for (int i = 1; i <= s.size(); i++) {
            arr[i][1] = arr[i-1][1] + (s[i-1] == '1');
            arr[i][2] = arr[i-1][2] + (s[i-1] == '2');
            arr[i][3] = arr[i-1][3] + (s[i-1] == '3');
        }

        int i = 0;
        for (int j = 1; j <= s.size(); j++) 
            while (arr[j][1]-arr[i][1] > 0 && arr[j][2]-arr[i][2] > 0 && arr[j][3]-arr[i][3] > 0)
                res = min(res, arr[j][1]-arr[i][1] + arr[j][2]-arr[i][2] + arr[j][3]-arr[i][3]),
                i += 1;
        
        cout << (res != INT_MAX ? res : 0) << endl;
        res = INT_MAX;
    }

    return 0;
}