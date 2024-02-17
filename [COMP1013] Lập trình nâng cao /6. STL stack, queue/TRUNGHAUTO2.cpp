#include <iostream>
#include <stack>
#include <map>
using namespace std;

bool check(string str) {
    return str != "*" && str != "/" && str != "+" && str != "-" && str != "(" && str != ")";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    map<string, int> mapString = {{ "*", 2 }, { "/", 2 }, { "+", 1 }, { "-", 1 }};
    stack<string> st;
    string tmp;
    
    while (cin >> tmp) {
        if (check(tmp)) cout << tmp << " ";

        else if (st.empty() || tmp == "(") st.push(tmp);

        else if (tmp == ")") {
            while (st.top() != "(") {
                cout << st.top() << " ";
                st.pop();
            }
            st.pop();

        } else if (mapString[tmp] <= mapString[st.top()]) {
            cout << st.top() << " ";
            st.pop();
            st.push(tmp);

        } else st.push(tmp);
    }

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
