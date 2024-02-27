#include <iostream>
using namespace std;
  
int main() {
    int n; 
    cin >> n;
    int a = n % 10;

    cout << "Nam ";
    switch (a) {
        case 0: cout << "muoi"; break;
        case 1: cout << "muoi mot"; break;
        case 2: cout << "muoi hai"; break;
        case 3: cout << "muoi ba"; break; 
        case 4: cout << "muoi bon"; break;
        case 5: cout << "muoi lam"; break;
        case 6: cout << "muoi sau"; break;
        case 7: cout << "muoi bay"; break;
        case 8: cout << "muoi tam"; break;
        case 9: cout << "muoi chin"; break;
    }

    return 0;
}