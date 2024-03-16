#include <iostream>
using namespace std;

int main() {
    int n, am = 0, duong = 0; 
    string str; 
    cin >> n;

    while (cin >> str) {
        if (str[0] == '-') am++;
        else if (str[0] != '0') duong++;
    }
    
    cout << am << " " << duong;
    return 0;
}