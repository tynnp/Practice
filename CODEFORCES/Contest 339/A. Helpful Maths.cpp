#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;
    string str;
    cin >> str;

    for (auto c : str) 
        if (c != '+') v.push_back(c - '0');
    sort(v.begin(), v.end());

    cout << v[0];
    for (int i = 1; i < v.size(); i++)
        cout << '+' << v[i];

    return 0;
}