#include <iostream>
#include <iomanip>
using namespace std;
  
int main() {
    double n, x, tong = 0; 
    cin >> x >> n;

    if (n <= 0 || x <= 0) cout << -1; 
    else {
        for (int i = 1; i <= n; i++) 
            tong += 1/(i*x*(i+1));
        cout << fixed << setprecision(3) << tong;
    }
    
    return 0;
}