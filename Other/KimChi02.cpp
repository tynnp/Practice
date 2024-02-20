#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<string> str = {"ABSINTH", "TEQUILA", "VODKA", "WHISKEY", "WINE", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE"};
    int n, cnt = 0; 
    string st; cin >> n; 

    while (n--) {
        cin.ignore(); 
        cin >> st; 

        if (st >= "1" && st <= "99") {
            if (stoi(st) < 18) cnt++;
        } else 
            for (int i = 0; i < str.size(); i++)
                if (st == str[i]) cnt++;
    }

    cout << cnt;
    return 0;
}