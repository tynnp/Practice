#include <iostream>
using namespace std;

int main() {
    int nam, thang; 
    cin >> thang >> nam;

    switch (thang) {
        case 1: cout << "Co 31 ngay"; break;
        case 3: cout << "Co 31 ngay"; break;
        case 4: cout << "Co 30 ngay"; break;
        case 5: cout << "Co 31 ngay"; break;
        case 6: cout << "Co 30 ngay"; break;
        case 7: cout << "Co 31 ngay"; break;
        case 8: cout << "Co 31 ngay"; break;
        case 9: cout << "Co 30 ngay"; break;
        case 10: cout << "Co 31 ngay"; break;
        case 11: cout << "Co 30 ngay"; break;
        case 12: cout << "Co 31 ngay"; break;
        default:
            if (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0)) 
                cout << "Co 29 ngay";
            else    
                cout << "Co 28 ngay";     
    }
    
    return 0;
}