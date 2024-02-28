#include <iostream>
using namespace std;
 
int main() {
    string str; 
    getline(cin, str);

    for (int i = 0; i < str.size(); i++) {
        if (i == 0 || str[i-1] == ' ') {
            if (str[i] >= 'a' && str[i] <= 'z') 
                str[i] -= 32;

        } else if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;
    }
    
    for (auto x : str) cout << x;
    return 0;
}