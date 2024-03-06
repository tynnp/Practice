#include <iostream>
using namespace std;

int main() {
    string s1, s2;
    int cnt = 0, j = 0;
    getline(cin, s1);
    getline(cin, s2);

    for (int i = 0; i < s1.length(); i++) {
        while (s1[i] != s2[j]) j++, cnt++;
        if (j > s2.length()) break;
        j++;
    }

    if (j > s2.length()) cout << "NO";
    else cout << "YES\n" << cnt;
    
    return 0;
}