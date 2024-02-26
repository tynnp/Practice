#include <iostream>
#include <set>
using namespace std;
 
int main() {
    string str1, str2; 
    getline(cin, str1); 
    getline(cin, str2); 
    multiset<char> st1, st2;
    for (auto x : str1) st1.insert(x);
    for (auto x : str2) st2.insert(x);
    cout << (st1 == st2 ? "YES" : "NO");   
    return 0;
}