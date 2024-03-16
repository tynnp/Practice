#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n; 
    cin >> n; 
    double arr[n]; 
    for (double &x : arr) cin >> x;

    stack<pair<double, int>> st; 
    st.push({999999, -1});
    for (int i = 0; i < n; i++) 
        if (arr[i] < st.top().first && arr[i] > 0) 
            st.pop(), st.push({arr[i], i});

    cout << st.top().second;
    return 0;
}