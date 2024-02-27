#include <iostream>
using namespace std;
 
int main() {
    string hinh; 
    cin >> hinh;

    if (hinh == "hcn") {
        double a, b; 
        cin >> a >> b;
        cout << "C = " << (a+b)*2;
    } else {
        double a; 
        cin >> a;
        cout << "C = " << a*4;
    }
    
    return 0;
}