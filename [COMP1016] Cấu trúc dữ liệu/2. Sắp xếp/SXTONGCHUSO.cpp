#include <iostream>
#include <vector>
using namespace std;

int tongChuSo(int n) {
    int res = 0;
    while (n > 0) 
        res += n%10, n /= 10;
    return res;
}

bool checkNT(int n) {
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return n > 1;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    vector<int> res;

    for (int &x : arr) {
        cin >> x;
        if (checkNT(tongChuSo(x))) 
            res.push_back(x);
    }

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;

    for (int i = 0; i < n; i++) 
        for (int j = i+1; j < n; j++) 
            if (tongChuSo(arr[i]) < tongChuSo(arr[j]))
                swap(arr[i], arr[j]);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}