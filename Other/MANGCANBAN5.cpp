#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    char c;
    vector<char> arr; 
    vector<char>::iterator it, it2;
    while (cin >> c) arr.push_back(c);
    
    for (it = arr.begin(); it != arr.end(); it++)
        cout << *it << " ";

    it = arr.begin() + 2; 
    it2 = arr.end() - 2;
    
    cout << endl << *it << " " << *it2;
    return 0;
}