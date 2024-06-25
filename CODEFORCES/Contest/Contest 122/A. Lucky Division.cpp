#include <bits/stdc++.h>
using namespace std;

vector<int> vt;

void numLucky(string num) {
    if (num.size() > 3) return;
    if (num.size() > 0 && num.size() < 4) vt.push_back(stoi(num));
    numLucky(num + '4');
    numLucky(num + '7');
}

bool check(int n) {
    for (int i = 0; i < vt.size(); i++)
        if (n % vt[i] == 0) return true;
    return false;
}

int main() {
    int n;
    string num = "";
    numLucky(num);
    cin >> n;
    cout << (check(n) ? "YES" : "NO");
    return 0;
}