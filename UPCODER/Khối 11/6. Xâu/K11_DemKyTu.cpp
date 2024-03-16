#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s1; 
    char c; 
    int cnt = 0;

    getline(cin, s1);
    cin >> c;

    for (int i = 0; i < s1.length(); i++)
        cnt += (c == s1[i]);
    
    cout << cnt;
    return 0;
}