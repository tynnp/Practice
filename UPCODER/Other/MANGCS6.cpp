#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr;
    int n;
    while (cin >> n) arr.push_back(n);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
        if (arr[i] % 2 != 0) cout << 0 << " ";
    }
    
    return 0;
}