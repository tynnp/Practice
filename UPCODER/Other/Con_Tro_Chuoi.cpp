#include <iostream>
#include <set>
using namespace std;

int main() {
    string tmp;
    set<string> s;

    while (cin >> tmp)
        s.insert(tmp);

    for (auto c : s)
        cout << c << endl;

    return 0;
}