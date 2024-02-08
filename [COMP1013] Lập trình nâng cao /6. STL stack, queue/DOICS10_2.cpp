#include <iostream>
#include <stack>
using namespace std;

int main() {
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