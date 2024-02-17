#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string number; cin >> number;
    int res = 0;

    for (char c : number) 
        res += c - '0';
    
    while (res >= 10) {
        int tmp = res;
        res = 0;
        
        while (tmp > 0) {
            res += tmp % 10,
            tmp /= 10;
        } 
    }

    cout << res;
    return 0;
}