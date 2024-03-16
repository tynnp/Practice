#include <iostream>
#include <iomanip>
using namespace std;
 
int main() {
    double n; 
    cin >> n;
    double tich = n*n;
    double tong = n*(n+1)/2;
    cout << fixed << setprecision(3) << tich/tong;
    return 0;
}