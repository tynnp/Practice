#include <iostream>
using namespace std;

bool SNT_Cung_Nhau(int a, int b) {
    if (b == 0) {
        if (a == 1) return true;
        else return false;
    }
    return SNT_Cung_Nhau(b, a % b);
}
 
int main() {
    int a, b; 
    cin >> a >> b;
    cout << (SNT_Cung_Nhau(a , b) ? "Yes" : "No");
    return 0;
}