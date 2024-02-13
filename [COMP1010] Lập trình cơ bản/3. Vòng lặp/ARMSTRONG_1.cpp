#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int sum, len, number[10][10];
    string n;

    for (int j = 0; j <= 9; j++)
        number[1][j] = j;

    for (int i = 2; i <= 9; i++) 
        for (int j = 0; j <= 9; j++)
            number[i][j] = number[i-1][j] * j;

    // for (int i = 1; i <= 9; i++) {
    //     for (int j = 1; j <= 9; j++) 
    //         cout << number[i][j] << " ";
    //         cout << endl;
    // }

    while (cin >> n) {
        sum = 0;
        len = n.length();
        for (int i = 0; i < len; i++)
            sum += number[len][n[i]-48];
        cout << (sum == stoi(n) ? "YES\n" : "NO\n");
    }

    return 0;
}