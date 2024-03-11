#include <iostream>
#include <cmath>
#include <bitset>
using namespace std;

int doi2sang10(string str) {
    int res = 0;
    for (int i = str.length()-1; i >= 0; i--)
        if (str[i] == '1') res += pow(2, str.length()-1-i);
    return res;
}

string doi10sang2(int he10) {
    string he2 = bitset<32>(he10).to_string();
    he2.erase(0, he2.find_first_not_of('0'));
    return he2;
}

int congHaiBit(char a, char b, int tmp) {
    int x = a - '0';
    int y = b - '0';
    return x + y + tmp;
}

void dichPhai(string &s, int lenBitA, int lenBitB) {
    s = '0' + s.substr(0, lenBitA + lenBitB); 
}

string nhanNhiPhan(int a, int b) {
    string bitB = doi10sang2(b);
    int lenBitA = doi10sang2(a).size();
    int lenBitB = doi10sang2(b).size();
    int count = lenBitA;
    
    string s(lenBitB, '0');
    s = '0' + s + doi10sang2(a);
    
    while (count--) {
        if (s[lenBitA + lenBitB] == '0') {
            dichPhai(s, lenBitA, lenBitB);
        } else {
            int tmp = 0;
            
            for (int i = lenBitB; i >= 1; i--) {
                int res = congHaiBit(s[i], bitB[i-1], tmp);
                if (res == 2) s[i] = '0', tmp = 1;
                else if (res == 1) s[i] = '1', tmp = 0;
                else s[i] = '0', tmp = 0;
            }
            
            s[0] = tmp + '0';
            dichPhai(s, lenBitA, lenBitB);
        }
    }
    
    return s;
}

int main() {
    int a, b;
    cin >> a >> b;
    string res = nhanNhiPhan(a, b);
    cout << doi2sang10(res);
    return 0;
}