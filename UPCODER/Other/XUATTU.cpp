#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    vector<string> arr; 
    string str;

    while (cin >> str) 
        arr.push_back(str);

    cout << arr[0];
    for (int i = 1; i < arr.size(); i++) 
        cout << "\n" << arr[i];
    
    return 0;
}