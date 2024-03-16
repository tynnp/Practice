#include <iostream>
using namespace std;
 
int main() {
    int a, so_thang = 1; 
    cin >> a;
    double so_tien_loi = a*0.1;

    while (so_tien_loi < a) {
        so_tien_loi += (a + so_tien_loi)*0.1;
        so_thang++;
    }
    
    cout << so_thang;
    return 0;
}