#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; 
    cin >> n >> m;

    bool check1[n+1], check2[n+1];
    memset(check1, true, sizeof(check1));
    memset(check2, true, sizeof(check2));

    stack<int> st;
    while (m--) {
        int disc; cin >> disc;
        st.push(disc);
    }

    while (!st.empty()) {
        int disc = st.top();
        check1[disc] = false;

        if (check2[disc]) cout << disc << " ";
        check2[disc] = false;

        st.pop();
    }

    for (int i = 1; i <= n; i++)
        if (check1[i]) cout << i << " ";

    return 0;
}