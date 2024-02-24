#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    if (a % 2 == 0 && b % 2 != 0) {
        for (int i = 1; i <= a; i++)
            cout << "Em xin hua khong gian lan\n";

    } else if (a % 2 != 0 && b % 2 == 0) {
        for (int i = 1; i <= b; i++)
            cout << "Neu gian lan se bi 0 diem toan bai thi\n";

    } else if (a % 2 == 0 && b % 2 == 0) {
        for (int i = 1; i <= a+b; i++)
            cout << "Em se co gang hoc tap tot\n";

    } else {
        for (int i = 1; i <= a*b; i++)
            cout << "Bai nay kho qua\n";
    }

    return 0;
}