#include <iostream>
#include <iomanip>
using namespace std;

double run(int n){
    if ( n == 0) return 0;
    else return 1.0 / (2 * n) + run(n - 1);
}
int main(){
    int n; 
    cin >> n;
    cout << fixed << setprecision(3) << run(n);
    return 0;
}