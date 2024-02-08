#include <iostream>
#include <vector>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    vector<int> vt;

    if (str.length() < 3) {
        int a = str[0] - 48;
        int n;
        while (cin >> n) vt.push_back(n);

        if (str[0] != '-')
            vt.erase(vt.begin() + a);
        else 
            vt.clear();

    } else {
        int a = str[0] - 48;
        int b = str[2] - 48;
        int n;
        while (cin >> n) vt.push_back(n);
        vt.erase(vt.begin() + a, vt.begin() + b);
    }

    if (!vt.empty()) 
        for (int i = 0; i < vt.size(); i++)
            cout << vt[i] << " ";
    else cout << "empty";

    return 0;
}