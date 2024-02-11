#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str; cin >> str;
    int max = str[0]-48;
    if (max < str[1]-48) max = str[1]-48;
    if (max < str[2]-48) max = str[2]-48;
    if (max < str[3]-48) max = str[3]-48;

    int min = str[0]-48;
    if (min > str[1]-48) min = str[1]-48;
    if (min > str[2]-48) min = str[2]-48;
    if (min > str[3]-48) min = str[3]-48;

    cout << min + max;
    return 0;
}