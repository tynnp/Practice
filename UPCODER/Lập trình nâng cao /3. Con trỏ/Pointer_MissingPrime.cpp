#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    bool *check = new bool[10000];
    for (int i = 0; i <= 10000; i++)
        check[i] = true;
    check[0] = false;
    check[1] = false;

    for (int i = 2; i*i <= 10000; i++) {
        if (check[i] == true) {
            for (int j = i*i; j <= 10000; j += i)
                check[j] = false;
        } 
    }

    int a, b; 
    cin >> a >> b;

    for (int i = a; i <= b; i++) 
        if (check[i]) cout << i << " ";

    delete[] check;
    return 0;
}
