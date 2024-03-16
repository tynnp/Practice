#include <iostream>
using namespace std;

int main() {
    int n; 
    cin >> n;
    
    for (int i = 1; i <= n; i += 2) 
        if (i != 5 && i != 7 && i != 93)
            cout << i << " ";
    
    return 0;
}