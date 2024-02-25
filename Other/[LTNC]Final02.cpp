#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
 
int main() {
    string str, token; 
    getline(cin, str);
    vector<string> st; 
    char ki_tu; 
    cin >> ki_tu;

    for (int i = 1; i < str.size(); i++) 
        if (str[i-1] == str[i] && str[i] == ki_tu)
            str.erase(i, 1), i--;

    if (str[0] == ki_tu) str.erase(0, 1);
    if (str[str.size()-1] == ki_tu) str.erase(str.size()-1, 1);
    //for (auto x : str) cout << x;

    istringstream iss(str);
    while (getline(iss, token, ki_tu))
        st.push_back(token);

    cout << st.size() << endl;
    for (auto x : st) cout << x << endl;
    return 0;
}