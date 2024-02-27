#include <iostream>
using namespace std;
 
int main() {
    int n; 
    cin >> n;
    cout << (n % 2 == 0 || n % 5 == 0 ? "Có" : "Không");
    return 0;
}