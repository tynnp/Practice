#include <iostream>
using namespace std;

int main() {    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    int k = s1.find(s2);
    cout << (k != -1 ? k : 0);
    return 0;
}