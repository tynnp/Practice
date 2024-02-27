#include <iostream>
using namespace std;
 
int main() {
    int n; 
    cin >> n;
    int arr[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    for (int i = 0; i < n; i++) {
        int tong_ngang = 0;
        for (int j = 0; j < n; j++)
            tong_ngang += arr[i][j];
        cout << tong_ngang << " ";
    } 
    cout << endl;

    for (int i = 0; i < n; i++) {
        int tong_doc = 0;
        for (int j = 0; j < n; j++)
            tong_doc += arr[j][i];
        cout << tong_doc << " ";
    } 
    
    return 0;
}