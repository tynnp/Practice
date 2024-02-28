#include <iostream>
#include <string>
#define hihi long long
using namespace std;

int main() {
    string n; 
    cin >> n;
    hihi tong_cac_so = 0;
    for (char c : n) tong_cac_so += (int) c - 48;
    cout << tong_cac_so;
}