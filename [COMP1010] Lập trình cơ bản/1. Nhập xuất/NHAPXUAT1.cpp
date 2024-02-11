#include <iostream>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string str; cin >> str;
    cout << str[2] << '\n';
    cout << str[0] << '\n';
    cout << str[1];
    return 0;
}