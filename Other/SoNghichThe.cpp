#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> setInt;
    int n, tmp;
    cin >> n;

    while (n--) {
        cin >> tmp;
        setInt.insert(tmp);
    }

    cout << setInt.size() - 1;
    return 0;
}