#include <iostream>
#include <vector>
using namespace std;

vector<bool> nt(1000001, true);

bool check(int n) {
    int cnt(0);
    for (int i = 2; i <= n/2; i++) {
        if (nt[i] && n % i == 0) cnt++;
        if (cnt == 3) return true;
    }
    return false;
}

bool doiXung(string n) {
    int i = 0;
    int j = n.size()-1;

    while (i < j) {
        if (n[i] != n[j]) return false;
        i++, j--;
    }

    return true;
}

int main() {
    int a, b;
    cin >> a >> b;

    nt[0] = nt[1] = false;
    for (int i = 2; i*i <= b + 1; i++)
        if (nt[i]) 
            for (int j = i*i; j <= b + 1; j += i) 
                nt[j] = false;

    int cnt(0);
    for (int i = a; i <= b; i++)
        if (check(i) && doiXung(to_string(i))) cnt++;

    cout << cnt;
    return 0;
}