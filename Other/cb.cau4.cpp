#include <iostream>
using namespace std;
 
int main() {
    float can_nang, chieu_cao; 
    cin >> can_nang >> chieu_cao;
    float BMI = can_nang/(chieu_cao*chieu_cao);

    if (BMI < 18.5) cout << "THIEU CAN";
    else if (BMI <= 24.99) cout << "BINH THUONG";
    else if (BMI <= 29.99) cout << "THUA CAN";
    else cout << "BEO PHI";

    return 0;
}