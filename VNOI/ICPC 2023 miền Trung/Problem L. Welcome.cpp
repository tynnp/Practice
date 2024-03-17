#include <bits/stdc++.h>
using namespace std;

int main() {
    string tmp;
    string arr[] = {"Welcome", "Hue", "University", "of", "Sciences"};
    vector<string> vt;
    while (cin >> tmp) vt.push_back(tmp);
    
    int i;
    for (i = 0; i < 5; i++) 
        if (find(vt.begin(), vt.end(), arr[i]) == vt.end()) break;
    
    cout << (i == 5 ? "Yes" : "No"); 
    return 0;
}