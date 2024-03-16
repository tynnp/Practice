#include <iostream>
#include <set>
using namespace std;
 
int main() {
    set<int> soam; 
    int n;

    while (cin >> n) {
        if (n < 0 && soam.find(n) == soam.end()) 
            cout << n << " ";
        if (n < 0) soam.insert(n);
    }

    if (soam.empty()) cout << "NOT FOUND";
    return 0;
}