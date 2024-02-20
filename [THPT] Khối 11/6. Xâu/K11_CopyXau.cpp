#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    int a, b;
    getline(cin, str);
    cin >> a >> b;

    if (a >= str.length() || b >= str.length()) cout << "gioi han khong dung";
    else for (int i = a; i <= b; i++)
        cout << str[i];
    return 0;
}