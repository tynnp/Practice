#include <iostream>
using namespace std;
 
int main() {
    string str; 
    getline(cin, str);
    int k = str.size(), a = 0;

    while (a < k) {
        int dem = 0; 
        char ch; 
        int i = a;

        for (int j = i; j < k; j++) {
            dem++; 
            ch = str[i];
            if (str[j] != str[j+1]) {
                a = j+1; 
                break;
            }
        }
        cout << dem << ch;
    }

    return 0;
}