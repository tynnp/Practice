#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int arr[200];
    for (int &x : arr) x = 0;

    string str;
    getline(cin, str);

    for (char c : str) 
        arr[tolower(c)]++;

    for (char c = 'a'; c <= 'z'; c++)
        if (arr[c] > 0) 
            cout << c << " : " << arr[c] << endl;
    
    return 0;
}