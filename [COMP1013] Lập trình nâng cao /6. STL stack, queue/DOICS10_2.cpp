#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    stack<int> intStack;
    if (n == 0) intStack.push(0);

    while (n > 0) {
        intStack.push(n % 2);
        n /= 2;
    }

    while (!intStack.empty()) {
        cout << intStack.top();
        intStack.pop();
    }

    return 0;
}