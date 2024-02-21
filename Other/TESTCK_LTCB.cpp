#include <iostream>
using namespace std;

int main() {
    int test_case; 
    cin >> test_case;
    cin.ignore();

    while (test_case) {
        string str; 
        getline(cin, str); 
        int k = -1;

        for (int i = k+1; i < str.length(); i++) { 
            if (str[i] == ' ') 
                cout << char(str[k+1] + 32), k = i;
            if (i == str.size()-1)
                for (int j = k+1; j < str.length(); j++) cout << str[j];
        }
        cout << endl; test_case--;
    }
    
    return 0;
}