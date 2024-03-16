#include <iostream>
#include <vector>
using namespace std;

bool check(string str) {
    char tmp[] = {'u', 'p', 'c', 'o', 'd', 'e', 'r'};
    int index = 0;

    for (char c : str) 
        if (c == tmp[index]) index++;
    return index == 7;
}

int main() {
    vector<int> vt;
    int test, index = 1;
    string str;
    cin >> test;

    while (test--) {
        cin >> str;
        if (check(str)) vt.push_back(index);
        index++;
    }

    cout << vt.size() << endl;
    for (int i = 0; i < vt.size(); i++)
        cout << vt[i] << " ";

    return 0;
}