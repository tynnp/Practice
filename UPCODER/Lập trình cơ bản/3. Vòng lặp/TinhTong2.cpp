#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tmp;
    while (cin >> tmp) {
        int tong = 0;

        while (tmp > 0) {
            int cnt = 0, number = tmp%10;
            for (int i = 2; i*i <= number; i++) 
                if (number % i == 0) cnt++;
            tong += (cnt == 0 && number > 1 ? number : 0);
            tmp /= 10;
        }
           
        cout << tong << '\n';
    }
    return 0;
}