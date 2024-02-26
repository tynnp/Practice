#include <iostream>
using namespace std;

int main() {
    int arr[10]; 
    for (int i = 0; i < 10; i++) 
        cin >> arr[i];

    int k, max = arr[0]; 
    for (int i = 0; i < 10; i++) 
        if (max < arr[i]) 
            max = arr[i], k = i;
        
    cout << k;
    return 0;
}