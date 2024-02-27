#include <iostream>
#include <cmath>
using namespace std;

bool check(int n) {
    int res = 0;
    for (int i = 1; i < n; i++)
        if (n % i == 0) res += i;
    return res == n;
}

int main() {
    int n;
    bool checkCP = false;
    cin >> n;

    int *arr = new int[n];
    int *res = new int[n];
    fill(res, res + n, 0);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
        if (check(arr[i])) 
            checkCP = true, res[i]++;

    if (checkCP) {
        cout << "cac phan tu la so hoan chinh\n";
        for (int i = 0; i < n; i++)
            if (res[i] != 0) cout << arr[i] << " ";
    } else cout << "mang khong co so hoan chinh";

    return 0;
}