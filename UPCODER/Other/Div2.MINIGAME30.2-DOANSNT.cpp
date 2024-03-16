#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int SIZE = 200005;
    vector<bool> prime(SIZE, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i*i <= SIZE; i++) 
        if (prime[i]) 
            for (int j = i*i; j <= SIZE; j += i)
                prime[j] = false;
    
    int n, i;
    cin >> n;

    if (prime[n]) cout << n << " " << n;
    else {
        i = n;
        while (!prime[--i]); cout << i << " ";
        while (!prime[++i]); cout << i;
    }
    
    return 0;
}