#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b; 
    cin >> a >> b;

    bool check[b+1];
    memset(check, true, sizeof(check));

    if (a < 2) {
        check[0] = false;
        check[1] = false;
    }

    for (int i = a; i*i <= b; i++) 
        if (check[i]) 
            for (int j = i*i; j <= b; j += i)
                check[j] = false;
        
    for (int i = a; i <= b; i++)
        if (check[i]) cout << i << endl;

    return 0;
}