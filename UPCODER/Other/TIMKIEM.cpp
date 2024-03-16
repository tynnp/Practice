#include <iostream>
using namespace std;

int main() {
    int k, n, res = 0; 
    cin >> k;
    while (cin >> n) if (n == k) res++;
    (res) ? cout << "TRUE\n" << res : cout << "FALSE\n" << res;
    return 0;
}