#include <iostream>
#include <string>
using namespace std;

string decimalToBaseT(int decimalNum, int baseT) {
    string result = "";
    
    while (decimalNum > 0) {
        int remainder = decimalNum % baseT;
        
        if (remainder < 10)
            result = char(remainder + '0') + result;
        else
            result = char(remainder - 10 + 'A') + result;
    
        decimalNum /= baseT;
    }
    
    return result;
}

int main() {
    int decimalNum;
    int baseT;
    cin >> decimalNum >> baseT;
    cout << decimalToBaseT(decimalNum, baseT);
    return 0;
}
