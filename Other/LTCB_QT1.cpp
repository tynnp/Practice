#include <iostream>
using namespace std;
 
int main() {
    int n, d, h, m, s; 
    cin >> n;
    d = n/86400; 
    h = (n%86400)/3600;
    m = ((n%86400)%3600)/60; 
    s = ((n%86400)%3600)%60;
    cout << d << ":" << h << ":" << m << ":" << s;
    return 0;
}