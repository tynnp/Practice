#include <iostream>
using namespace std;

int main() {
    int len, i(0);
    string str;
    cin >> len >> str;

    while (i < len) 
        if (str[i] == '1') {
            i++;
            while (i < len && isalpha(str[i])) 
                cout << str[i++];
            cout << " ";
            
        } else if (str[i] == '2') {
            i++;
            int start = i;
            while (i < len && isalpha(str[i])) i++;
            for (int j = i - 1; j >= start; j--) 
                cout << str[j];
            cout << " ";
        }

    return 0;
}
