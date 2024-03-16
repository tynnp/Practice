#include <iostream>
using namespace std;

bool check(int* arr, int n) {
    for (int i = 0; i <= n/2; i++) 
        if (*(arr + i) != *(arr + n - i - 1))
            return false;
    return true;
}

void print(int* arr, int n) {
    if (check(arr, n)) cout << "mang doi xung";
    else {
        cout << "mang khong doi xung" << endl;
        for (int i = 0; i < n/2; i++) 
            if (*(arr + i) != *(arr + n - i - 1))
                cout << *(arr + i) << " " << *(arr + n - i - 1) << endl;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) 
        cin >> arr[i];

    print(arr, n);
    delete[] arr;
    return 0;
}