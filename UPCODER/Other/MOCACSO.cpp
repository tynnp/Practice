#include <bits/stdc++.h>
using namespace std;

#define ll long long

string csl(const string &a, const string &b) {
    int len1 = a.size(), len2 = b.size();
    int maxLen = max(len1, len2);
    string result(maxLen + 1, '0'); 
    int carry = 0;

    for (int i = 0; i < maxLen; ++i) {
        int digitA = (i < len1) ? a[len1 - 1 - i] - '0' : 0;
        int digitB = (i < len2) ? b[len2 - 1 - i] - '0' : 0;
        int sum = digitA + digitB + carry;
        carry = sum / 10;
        result[maxLen - i] = (sum % 10) + '0';
    }

    if (carry) result[0] = carry + '0';
    else result.erase(result.begin()); 
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string str, n("0"), sum("0");
    getline(cin, str);
    
    for (auto &c : str)
        if (!isdigit(c)) c = ' ';
    
    stringstream ss(str);
    while (ss >> n)
        sum = csl(sum, n);
    
    while (sum[0] == '0') 
        sum.erase(sum.begin());
    
    cout << (sum == "" ? "0" : sum);
    return 0;
}