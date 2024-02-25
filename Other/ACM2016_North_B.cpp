#include <iostream>
#include <set>
using namespace std;
 
bool palindrome(string str) {
    for (int i = 0; i < str.size()/2; i++) 
        if (str[i] != str[str.size()-i-1]) return false;
    return true;
}

int main() {
    int test_case; 
    cin >> test_case; 

    while (test_case--) {
        string str; 
        set<string> st; 
        set<char> st2;

        cin >> str;
        for (auto x : str) st2.insert(x);

        for (int i = 2; i <= str.size(); i++) {
            for (int j = 0; j + i <= str.size(); j++) {
                string tmp = str.substr(j, i);
                if (palindrome(tmp)) st.insert(tmp);
            }
        }
        cout << st.size()+ st2.size() << endl;
    }

    return 0;
}