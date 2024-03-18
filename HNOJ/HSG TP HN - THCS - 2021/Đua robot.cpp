#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll check(ll s1, ll v1, ll s2, ll v2) {
    if (v1 == v2) return -1;
    ll res = (s2-s1)/(v1-v2);
    if (res >= 0) return res;
    return -1;
}

int main() {
    ifstream fin("DRB.INP");
    ofstream fout("DRB.OUT");

    ll s1, v1, s2, v2;
    fin >> s1 >> v1 >> s2 >> v2;
    fout << check(s1, v1, s2, v2);

    fin.close();
    fout.close();
    return 0;
}