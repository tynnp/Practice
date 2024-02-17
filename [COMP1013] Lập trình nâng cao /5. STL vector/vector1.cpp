#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> vt;
    int n;
    while (cin >> n) vt.push_back(n);

    vector<int>::iterator it;
    for (it = vt.begin(); it != vt.end(); it++)
        cout << *it << " ";
    cout << endl;

    vector<int>::reverse_iterator rit;
    for (rit = vt.rbegin(); rit != vt.rend(); rit++)
        cout << *rit << " ";

    return 0;
}