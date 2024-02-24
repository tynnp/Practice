#include <iostream>
using namespace std;

int main() {
    int n, tmp, res = 0;
    cin >> n;

    while (n--) {
        cin >> tmp;
        res += tmp;
    }
    
    cout << res; 
    return 0;
}