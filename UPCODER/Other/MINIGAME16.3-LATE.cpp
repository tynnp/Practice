#include <iostream>
#include <vector>
#include <set>
using namespace std;

long long giai_thua(int n) {
    if (n == 1 || n == 0) return 1;
    return n * giai_thua(n-1);
}

int main() {
    string str; 
    vector<string> st1;
    set<string> st2;

    while (cin >> str) {
        st1.push_back(str);
        st2.insert(str);
    }

    long long result = 1;
    for (auto a : st2) {
        int count = 0;
        for (auto b : st1) if (a == b) count++;
        result *= giai_thua(count);
    } 

    cout << giai_thua(st1.size()) / result;
    return 0;
}