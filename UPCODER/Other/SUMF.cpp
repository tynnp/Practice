#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

int main() {
    string line;
    stringstream ss;
    double n, sum = 0;
    
    while (getline(cin, line)) {
        sum = 0;
        ss << line;
        while (ss >> n) sum += n;
        cout << round(sum*1000)/1000 << endl;
        ss.clear();
    }
    
    return 0;
}