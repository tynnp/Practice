#include <iostream>
using namespace std;

int main() {
    double arr[5], index = -1;
    for (double &x : arr) cin >> x;

    for (int i = 0; i < 5; i++) 
        if (arr[i] > 0) index = arr[i]; 

    cout << index;
    return 0;
}   