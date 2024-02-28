#include <iostream>
using namespace std;

int main() {
    char c;
    cin >> c;
    cout << (c >= 'A' && c <= 'Z' ? 'A' : 'a');
    return 0;
}