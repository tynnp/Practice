#include <iostream>
using namespace std;
 
bool check(string str) {
    if (str == "TC" || str == "SGK" || str == "DNA" || str == "TT" || str == "TN") return true;
    else return false;
}

int money(string str) {
    if (str == "TC") return 18000;
    else if (str == "SGK") return 23000;
    else if (str == "DNA") return 15000;
    else if (str == "TT") return 45000;
    else if (str == "TN") return 12000;
}

int main() {
    string str; 
    int sum = 0;

    while (cin >> str) {
        if (check(str)) {
            int n; cin >> n;
            sum += money(str)*n;
        } else break;
    }
    
    int money = stoi(str);
    cout << sum << " VND\n";
    if (sum == money) cout << "0 VND";
    else cout << money - sum << " VND";
    return 0;
}