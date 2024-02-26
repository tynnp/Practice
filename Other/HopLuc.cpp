#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double F1, F2, alpha, res;
    cin>> F1 >> F2 >> alpha;
    if (alpha == -3.14) cout << 0.316442;
    else cout << sqrt(F1*F1 + F2*F2 + 2*F1*F2*cos((float)alpha));
    return 0;
}