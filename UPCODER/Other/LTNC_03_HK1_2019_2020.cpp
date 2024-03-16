#include <iostream>
#include <regex>
using namespace std;

bool check(const string& email) {
    regex pattern("[\\w\\.]+@[a-z0-9\\.]+[a-z0-9\\.-]\\.[a-z0-9]+$");
    return regex_match(email, pattern);
}

int main() {
    string email;
    cin >> email;
    cout << (check(email) ? "TRUE" : "FALSE")
    return 0;
}