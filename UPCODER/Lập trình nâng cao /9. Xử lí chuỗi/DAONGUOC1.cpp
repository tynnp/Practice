#include <iostream>
using namespace std;

int rToInt(string number) {
    int res = 0;

    for (int i = number.length()-1; i >= 0; i--) {
        if (number[i] == '-') res = -res;
        else res = res*10 + (number[i] - '0');
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string max = "-1000000";
    string number;

    while (cin >> number) 
        if (rToInt(max) < rToInt(number))
            max = number;
    
    cout << max;
    return 0;
}