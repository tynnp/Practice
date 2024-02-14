#include <iostream>
using namespace std;

void hoanVi(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    hoanVi(a, b);
    
    cout << a << " " << b;
    return 0;
}