#include <bits/stdc++.h>
using namespace std;

int countString(string s1, string s2) {
    int cnt = 0;
    size_t pos = 0;
    while ((pos = s1.find(s2, pos)) != string::npos)
        cnt++, pos += s2.length();
    return cnt;
}

int main() {
    ifstream fin("ARN.INP");
    ofstream fout("ARN.OUT");

    string s1, s2;
    fin >> s1 >> s2;   
    fout << countString(s1, s2);

    fin.close();
    fout.close();
    return 0;
}