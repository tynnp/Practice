#include <iostream>
using namespace std;
 
int main() {
    int n, x = 0; 
    cin >> n;

    while (n--) {
        char a, b, c; 
        cin >> a >> b >> c;

        switch (a) {
            case '+': ++x; break;
            case '-': --x; break;
            default: 
                switch (b) {
                    case '+': x++; break;
                    case '-': x--; break;
                }
        }
    }
    
    cout << x;
    return 0;
}