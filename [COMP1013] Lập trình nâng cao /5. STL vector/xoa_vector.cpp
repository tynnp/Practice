#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> vt;
    cin.ignore();

    string daySo;
    getline(cin, daySo);
    for (int i = 0; i < daySo.length(); i += 2)
        vt.push_back(daySo[i] - 48);

    string str;
    getline(cin, str);

    if (str.length() < 3) {
        if (str[0] == '-') vt.clear();
        else {
            int a = str[0] - 48;
            vt.erase(vt.begin() + a);
        }
    } else {
        int a = str[0] - 48;
        int b = str[2] - 48;
        vt.erase(vt.begin() + a, vt.begin() + b);
    }

    if (vt.empty()) cout << "empty";
    else {
        for (int i = 0; i < vt.size(); i++)
            cout << vt[i] << " ";
    }

    return 0;
}