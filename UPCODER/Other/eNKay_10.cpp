#include <iostream>
using namespace std;
 
int main() {
    int test, cnt = 0;
    cin >> test;
    cin.ignore();

    while (test--) {
        string str; 
        getline(cin, str);
        //cout << str << endl;
        for (int i = 1; i < str.size(); i++)
            if (str[i-1] == ' ' && str[i] != ' ') cnt++;
        if (str[str.size()-1] == ' ') cnt++;
    }
    
    cout << cnt;
    return 0;
}