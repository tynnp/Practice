#include <bits/stdc++.h>
using namespace std;

double logSoLon(const string &s) {
    double sum(0), tmp(1);

    for (int i = 0; i < s.size(); i++) 
        sum += tmp * (s[i] - '0'),
        tmp /= 10;
    
    return log(sum) + log(10) * (s.size()-1) ;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
  
    string s;
    double p, sum(0);
    
    cin >> s;
    p = logSoLon(s);
    int i = 1, j = 1;
    
    while (j <= 100000 || abs(sum - p) > 1e-6) {
        if (abs(sum - p) < 1e-6) break;
        else if (sum > p) sum -= log(i++);
        else sum += log(j++);
    }

    cout << i << " " << j-1;
    return 0;
}