#include <iostream>
using namespace std;

int main() {
    int n, i = 0; 
    cin >> n;
    string str = "I love ";

    while (++i <= n) {
        if (i % 2 == 0 && i > 1) str += "that I hate ";
        else if (i > 1) str += "that I love ";
        if (i == n) str += "it";
    }
    
    cout << str;
    return 0;
}