#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, sum, num, len;
    int number[10][9];
    bool check = true;

    for (int i = 0; i < 10; i++) {
        number[i][0] = 1;
        for (int j = 1; j <= 8; j++) 
            number[i][j] = number[i][j-1]*i;
    }

    // for (int i = 1; i < 10; i++) {
    //     for (int j = 1; j <= 8; j++) 
    //         cout << number[i][j] << " ";
    //         cout << endl;
    // }

    cin >> a >> b;
    for (int i = a; i <= b; i++) {
        int tmp = i;
        sum = 0, len = 0, num = i;

        while (tmp > 0) 
            len++, tmp /= 10;
        
        tmp = i;
        while (tmp > 0) {
            sum += number[tmp % 10][len];
            tmp /= 10;
            if (sum > i) {
                i -= i % 10, i += 9;
                break;
            }
        }

        if (sum == num) {
            cout << i << ' ';
            check = false;
        } 
    }

    if (check) cout << -1;
    return 0;
}