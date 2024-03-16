#include <iostream>
using namespace std; 
#define ll long long

int dig[] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8}; 
  
ll lastNon0Digit(ll n) { 
    if (n < 10) return dig[n]; 
    if (((n/10)%10)%2 == 0) return (6*lastNon0Digit(n/5)*dig[n%10]) % 10; 
    else return (4*lastNon0Digit(n/5)*dig[n%10]) % 10; 
} 

int main() { 
    ll n;
    cin >> n;
    cout << lastNon0Digit(n); 
    return 0; 
} 