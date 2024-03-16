#include <iostream>
#include <vector>
using namespace std;

int main() {
    string tmp;
    bool check = true;
    vector<string> vt;
    
    while (cin >> tmp)  
        vt.push_back(tmp);

    for (int i = vt.size()-1; i >= 0; i--)
        if (vt[i][0] == 't') {
            cout << i << endl;
            check = false;
        }
    
    if (check) cout << -1;
    return 0;
}