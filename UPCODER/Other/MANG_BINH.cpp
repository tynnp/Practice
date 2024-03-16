#include <iostream>
#include <set>
using namespace std;
 
int main() {
    multiset<int> res;
    int n, k; 
    cin >> k; 

    while (cin >> n) 
        res.insert(n*n);

    multiset<int>::iterator it;
    for (it = res.begin(); it != res.end(); it++)
        cout << *it << " ";
    
    return 0;
}