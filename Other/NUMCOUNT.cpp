#include <iostream>
using namespace std;

int main() {
    string str;
    while (getline(cin, str)) {
        int dem = 0;
        for (int i = 0; i < str.size() - 1; i++)
            if (str[i] == ' ' && str[i+1] != ' ') dem++;

        if (str[0] == ' ') cout << dem << endl;
        else cout << dem + 1 << endl;
    }

    return 0;
}