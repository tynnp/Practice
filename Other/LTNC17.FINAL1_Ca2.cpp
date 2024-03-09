#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int check(string chuoi) {
    vector<int> numbers;
    istringstream iss(chuoi);
    string number_str;

    while (getline(iss, number_str, ',')) 
        numbers.push_back(stoi(number_str));

    int maxN = *max_element(numbers.begin(), numbers.end());
    int minN = *min_element(numbers.begin(), numbers.end());
    int res = maxN + minN;
    return res;
}

int main() {
    string chuoi;
    getline(cin, chuoi);
    cout << check(chuoi) << endl;
    return 0;
}