#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> str; string st; 
    while (cin >> st) str.push_back(st);
    for (auto x : str) 
        if (x.find('@') < x.size()) 
            cout << x << endl;
    return 0;
}