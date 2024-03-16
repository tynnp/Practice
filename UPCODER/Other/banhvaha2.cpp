#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> str; 
    string st; 
    while (cin >> st) str.push_back(st);
    for (int i = 0; i < str.size(); i++)
        if (str[i] == "password") 
            cout << i << endl;
    return 0;
}