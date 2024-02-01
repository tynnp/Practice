#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main() {
    vector<int> v;
    int n;

    while (cin >> n) v.push_back(n);
    vector<int>::iterator it1;
    vector<int>::reverse_iterator it2;

    for (it1 = v.begin(); it1 != v.end(); it1++)
        cout << *it1 << " ";
    cout << endl;

    for (it2 = v.rbegin(); it2 != v.rend(); it2++) 
        cout << *it2 << " ";

    return 0;
}