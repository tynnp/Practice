#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string str("");
    cin >> n;
    
    for (int i = 1; i <= n; i++)
        str += to_string(i);
    
    cout << str[n-1];
    return 0;
}
