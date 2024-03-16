#include <iostream>
using namespace std;

int timSoLonNhat(string str) {
    int soLonNhat = 0;
    int tmp = 0;

    for (char c : str) {
        if (isdigit(c)) 
            tmp = tmp*10 + (c - '0');
        else if (tmp > 0) {
            soLonNhat = max(soLonNhat, tmp);
            tmp = 0;
        }
    }

    if (soLonNhat < tmp) 
        soLonNhat = tmp;

    return soLonNhat;
}

int main() {
    string str;
    cin >> str;
    cout << timSoLonNhat(str);
    return 0;
}