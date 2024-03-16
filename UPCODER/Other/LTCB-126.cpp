#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n; 
    cin >> n; 
    float arr[n], sum = 0;
    for (float& x : arr) cin >> x;
    for (float x : arr) if (x < 0) sum += x; 
    cout << roundf(sum*100) / 100;
    return 0;
}