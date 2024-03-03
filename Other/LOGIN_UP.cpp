#include <iostream>
using namespace std;

bool check(string str) {
    char tmp[] = {'u', 'p', 'c', 'o', 'd', 'e', 'r'};
    int index = 0;

    for (char c : str) 
        if (c == tmp[index]) index++;
    return index == 7;
}

int main() {
    string str;
    cin >> str;
    cout << (check(str) ? "YES" : "NO");
    return 0;
}