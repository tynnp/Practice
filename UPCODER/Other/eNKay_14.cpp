#include <iostream>
#include <map>
using namespace std;
 
int main() {
    string str; 
    map<char, int> mp;
    getline(cin, str);

    string::iterator it;
    for (it = str.begin(); it != str.end(); it++) {
        *it = tolower(*it);
        if (*it == ' ') str.erase(it--);
    }

    for (char c : str) mp[c]++;
    for (pair<char, int> p : mp) 
        if ((p.first >= '0' && p.first <= '9') || p.first >= 'a' && p.first <= 'z')
            cout << p.first << " " << p.second << endl;
        
    return 0;
}