#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    char tmp;
    int arr[26];
    memset(arr, 0, sizeof(arr));
    while (cin >> tmp) arr[tmp - 97]++;

    for (int i = 0; i < 26; i++)
        if (arr[i] != 0) 
            cout << char(i + 97) << ":" << arr[i] << endl;
    
    return 0;
}