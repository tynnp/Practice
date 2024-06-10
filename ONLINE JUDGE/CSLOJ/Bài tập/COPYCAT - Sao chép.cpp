#include <bits/stdc++.h>
using namespace std;

ifstream fin("copycat.inp");
ofstream fout("copycat.out");

int main() {
    int n;
    fin >> n;
    fin.ignore();

    while (n--) {
        string s;
        fin >> s;
        fout << s << '\n';
    }

    return 0;
}