#include <iostream>
using namespace std;
 
int main() {
    int n, res = 0; 
    
    while (cin >> n) {
        while (n) {
            if (n%10 % 2 == 0) 
                res += n%10;
            n /= 10;
        } 
        cout << res << endl;
    }

    return 0;
}