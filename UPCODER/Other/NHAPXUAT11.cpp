#include <iostream>
using namespace std;

int main() {
    int x;
    bool check = false;
    
    while (cin >> x) {
        
        if (check)
            cout << '\n';
            
        cout << x;
        check = true;
    }
    
    return 0;
}
