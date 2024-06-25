#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string str;
    cin >> str;

    while (k--) 
        for (int i = 1; i < n; i++)
            if (str[i-1] == 'B' && str[i] != str[i-1])
                str[i-1] = str[i], str[i] = 'B', i++;
    
    cout << str;
    return 0;
}