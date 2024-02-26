#include <iostream>
using namespace std;
 
int main() {
    string str; 
    getline(cin, str);
    int k = 0;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] != '0') k++;
        for (int j = i+1; j < str.size(); j++) {
            if (str[i] == str[j]) str[j] = '0';
        }
    } 
    
    cout << k;
    return 0;
}