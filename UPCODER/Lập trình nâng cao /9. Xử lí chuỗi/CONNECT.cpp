#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream ifile; 
    ofstream ofile;
    ifile.open("CONNECT.INP");
    ofile.open("CONNECT.OUT"); 
    vector<int> vt;
    string res = "";
    
    int test; ifile >> test;
    while (test--) {
        int n; ifile >> n;
        vt.push_back(n);
    }

    sort(vt.begin(), vt.end(), [] (int a, int b) {
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    });

    for (int x : vt)
        res += to_string(x);
    ofile << res;

    ifile.close();
    ofile.close();
    return 0;
}