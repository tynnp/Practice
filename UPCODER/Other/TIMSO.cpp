#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string number;
    getline(cin, number);
    bool check = (number[0]-48) + (number[1]-48) == (number[2]-48) * (number[3]-48); 
    cout << (check ? "yes" : "no");
    return 0;
}