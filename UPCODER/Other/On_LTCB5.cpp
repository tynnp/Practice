#include <iostream>
using namespace std;
 
int main() {
    int n; 
    cin >> n;
    int arr[n], res = 1;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 1; i < n; i++) if (arr[i - 1] <= arr[i]) res++;
    cout << res;
    return 0;
}