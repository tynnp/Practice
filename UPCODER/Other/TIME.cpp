#include <iostream>
using namespace std;
 
int main() {
    int testcase; 
    cin >> testcase;

    while (testcase--) {
        int n; 
        cin >> n;
        int hours = 8 + n / 60;
        int minute = n % 60;
        if (hours < 10) cout << 0;
        cout << hours << ":";
        if (minute < 10) cout << 0;
        cout << minute << endl;
    }
    
    return 0;
}