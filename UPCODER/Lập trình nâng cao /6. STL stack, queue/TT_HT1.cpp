#include <iostream>
#include <map>
#include <stack>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    map<char, int> mapChar = {{'^', 3}, {'*', 2}, {'/', 2}, {'+', 1}, {'-', 1}};
    stack<char> st; 
    char tmp;

    while (cin >> tmp) {
        if (tmp >= 'a' && tmp <= 'z') cout << tmp;

        else if (st.empty() || tmp == '(') st.push(tmp);

        else if (tmp == ')') {
            while (st.top() != '(') {
                cout << st.top();
                st.pop();
            }
            st.pop();

        } else if (mapChar[tmp] <= mapChar[st.top()]) {
            cout << st.top();
            st.pop();
            st.push(tmp);

        } else st.push(tmp);
    }

    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }

    return 0;
}