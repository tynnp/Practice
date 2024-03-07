#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long arr2kg[4];
    long long arr1kg[3];
    
    long long Q, H, S, D, N;
    cin >> Q >> H >> S >> D >> N;

    arr2kg[0] = Q*8; arr1kg[0] = Q*4;
    arr2kg[1] = H*4; arr1kg[1] = H*2;
    arr2kg[2] = S*2; arr1kg[2] = S;
    arr2kg[3] = D;

    long long min2kg = *min_element(arr2kg, arr2kg + 4);
    long long min1kg = *min_element(arr1kg, arr1kg + 3);

    cout << N/2 * min2kg + N%2 * min1kg;
    return 0;
}