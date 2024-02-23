#include <iostream>
using namespace std;

int main() {
    int A[] = {1, 5, 6, 4, 11, 9, 8};
    A[4] = 2;
    for (int x : A) 
        if (!(x & 1)) 
            cout << x << "\n";
    return 0;
}