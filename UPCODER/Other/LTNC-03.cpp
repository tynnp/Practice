#include <iosrteam>
#include <stack>
using namespace std;

int main() {
    string str; 
    stack<char> hihi;
    cin >> str;

    for (int i = 0; i < str.size(); i++)
        if ((i+1) % 2 == 0) hihi.push(str[i]);

    while (!hihi.empty()) {
        cout << hihi.top();
        hihi.pop();
    }

    return 0;
}