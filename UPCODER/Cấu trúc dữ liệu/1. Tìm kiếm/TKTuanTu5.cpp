#include <iostream>
using namespace std;

int main() {
    int n, x, k, tmp = 1;
    cin >> n >> x >> k;
    int arr[n]; 
    bool check = true, check2 = true;

    for (int i = 0; i < n; i++) 
        cin >> arr[i];

    for (int i = 0; i < n; i++) 
        if (arr[i] == x) {
            cout << i; 
            check = false;
            break;
        }

    if (check) {
        while (tmp <= k) {
            int tmp1 = -1, tmp2 = -1;

            for (int i = 0; i < n; i++) 
                if (arr[i] == x + tmp) {
                    tmp1 = i; 
                    break;
                }
            
            for (int i = 0; i < n; i++) 
                if (arr[i] == x - tmp) {
                    tmp2 = i; 
                    break;
                } 

            if (tmp1 != -1 && tmp2 != -1) {
                if (tmp1 > tmp2) cout << tmp2;
                else cout << tmp1;
                check2 = false;
                break; 

            } else if (tmp1 != -1 || tmp2 != -1) {
                if (tmp1 != -1) cout << tmp1;
                else if (tmp2 != -1) cout << tmp2;
                check2 = false;
                break; 
            } 

            tmp++;
        }

        if (check && check2) cout << -1;
    }

    return 0;
}