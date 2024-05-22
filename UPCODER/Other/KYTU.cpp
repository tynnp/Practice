#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    int res(INT_MIN);
    cin >> str;
    
    str.erase(remove_if(str.begin(), str.end(), ::islower), str.end());
    vector<int> dp(str.size()+1, 1);
    
    for (int i = 0; i < str.size(); i++) {
        for (int j = 0; j < i; j++) 
            if (str[j] < str[i])
                dp[i] = max(dp[i], dp[j] + 1);
        res = max(res, dp[i]);
    }
    
    cout << (str == "" ? 0 : res);
    return 0;
}