#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    string str; 
    vector<string> st;
    while (cin >> str) st.push_back(str);

    if (st.size() == 2) 
        cout << "Ho: " << st[0] << endl << "Ten: " << st[1]; 
    else {
        cout << "Ho: " << st[0] << endl;
        cout << "Lot: ";
        for (int i = 1; i < st.size()-1; i++)
            cout << st[i] << " ";
        cout << endl << "Ten: " << st.back();
    }

    return 0;
}