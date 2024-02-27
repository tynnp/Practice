#include <iostream>
using namespace std;
 
int main() {
    int n, cnt = 0; 
    char c; 
    string str;
    cin >> n >> c >> str;
    for (char x : str) if (x == c) cnt++;
    cout << cnt*n;
    return 0;
}