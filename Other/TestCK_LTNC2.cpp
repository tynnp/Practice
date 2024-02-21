#include <iostream>
#define endl '\n'
#define MAX 99999999
#define MIN -99999999
using namespace std;

int arr[10000], n, k;

void Dong_1(int max) {
    int max2 = MIN;

    for (int i = 0; i < n; i++) 
        if (max2 < arr[i] && arr[i] < max) max2 = arr[i];

    if (max2 == MIN) cout << -1 << endl; 
    else {
        for (int i = 0; i < n; i++)
            if (arr[i] == max2) cout << i << " ";
        cout << endl;
    }
}

void Dong_2() {
    int viTri = -1, max3 = MIN;
    for (int i = 0; i < n; i++)
        if (max3 <= arr[i] && arr[i] <= k)
            max3 = arr[i], viTri = i;
    cout << viTri << endl;
}

void Dong_3() {
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && arr[j] <= arr[j-1]) 
            swap(arr[j], arr[j-1]), j--;
    }

    bool check = true;
    for (int i = 0; i < n; i++) 
        if (arr[i] > k) cout << arr[i] << " ",
        check = false;
    if (check) cout << "00";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    int max = MIN;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (max < arr[i]) max = arr[i];
    }

    Dong_1(max);
    Dong_2();
    Dong_3();
    
    return 0;
}