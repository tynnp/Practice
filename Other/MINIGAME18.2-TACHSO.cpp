#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string str, token; 
    vector<string> st; 
    int k = 0;
    
    getline(cin, str);
    istringstream iss(str);

    while (getline(iss, token, ','))
        st.push_back(token);

    int result = 0;
    for (auto x : st) 
        result += stoi(x), cout << x << endl; 
    
    cout << result;
    return 0;
}