#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int rToInt(string number) {
    int res = 0;

    for (int i = number.length()-1; i >= 0; i--) {
        if (number[i] == '-') res = -res;
        else res = res*10 + (number[i] - '0');
    }

    return res;
}

int main() {
    ifstream ifile; ifile.open("inDaoNguoc2.txt");
    ofstream ofile; ofile.open("outDaoNguoc2.txt");

    string max = "-1000000";
    string number;
    int index = 0;
    vector<int> vt; 

    vt.push_back(0);
    while (ifile >> number) {
        if (rToInt(max) < rToInt(number)) {
            max = number;
            vt.clear();
            vt.push_back(index);
            
        } else if (rToInt(max) == rToInt(number))
            vt.push_back(index);

        index++;
    }
    
    ofile << max << endl;
    if (vt.size() > 1) 
        for (int x : vt) ofile << x << " ";

    ifile.close();
    ofile.close();
    return 0;
}