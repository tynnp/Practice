#include <iostream>
#include <fstream>
#include <set>
using namespace std;

int daoNguoc(string str) {
    int res = 0;
    bool check = false;
    if (str[0] == '-') check = true;

    for (int i = str.length()-1; i >= 0; i--) {
        if (i == 0 && check) break;
        res = res*10 + (str[i] - '0');
    }

    if (check) res = -res;
    return res;
}

int main() {
    ifstream ifile;
    ofstream ofile;
    ifile.open("input.txt");
    ofile.open("output.txt");

    string tmp;
    multiset<int> setInt;

    while (ifile >> tmp) 
        setInt.insert(daoNguoc(tmp));

    auto lastElement = *setInt.rbegin();
    ofile << lastElement;

    ifile.close();
    ofile.close();
    return 0;
}