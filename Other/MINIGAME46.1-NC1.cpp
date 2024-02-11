#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, l; 
    multiset<string> setString;
    cin >> n >> l;

    while (n--) {
        string tmp;
        cin >> tmp;
        setString.insert(tmp);
    }
    
    for (auto str : setString)
        cout << str;
    return 0;
}