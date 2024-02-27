#include <iostream>
#include <cmath>
using namespace std;

int paintPixel(int r) {
    int count = 0;
    for (int x = -r; x <= r; x++) {
        for (int y = -r; y <= r; y++) 
            if (sqrt(x * x + y * y) <= r) 
                count++;
    }
    return count;
}
 
int main() {
    int r; 
    cin >> r;
    cout << paintPixel(r);
    return 0;
}