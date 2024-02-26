#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n; 
    cin >> n;
    long long arr[50][50];
    fill(&arr[0][0], &arr[0][0] + 50 * 50, 0);

    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            arr[i][0] = arr[i][i] = 1;
            if (i > 0 && j > 0)
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
        }
    }

    for (int i = 0; i < 50; i++) 
        if (arr[n-1][i] != 0)
            cout << arr[n-1][i] << " ";
        
    return 0;
}