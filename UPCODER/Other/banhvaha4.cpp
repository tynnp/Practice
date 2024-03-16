#include <iostream>
#include <map>
using namespace std;
 
int main() {
    int n; 
    map<string, int> mp;
    mp["eke"] = 0;
    mp["thang"] = 0;
    mp["dodo"] = 0;
    cin >> n;

    while (n--) {
        string str; 
        cin >> str;
        for (auto &x : mp) 
            if (str == x.first) x.second++;
    }

    cout << "eke " << mp["eke"] << endl;
    cout << "thang " << mp["thang"] << endl;
    cout << "dodo " << mp["dodo"] << endl;

    return 0;
}