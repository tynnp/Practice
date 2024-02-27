#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

bool checkNumber(string &str) {
    if (str[0] != '0') return false;
    if (str[1] < '0' || str[1] > '9') return false;
    for (int i = 0; i < str.length(); i++)
        if (str[i] < '0' || str[i] > '9') str.erase(i--, 1);
    if (str.length() != 9 && str.length() != 10) return false;
    return true;
}

int main() {
    ifstream ifile;
    ofstream ofile;
    ifile.open("BINHLUAN.TXT");
    ofile.open("SDT.TXT");

    vector<string> res;
    string tmp;

    while (ifile >> tmp) {
        if (checkNumber(tmp))
            res.push_back(tmp);
    }

    if (res.empty()) ofile << "HANG FAKE NEN KHONG AI MUA !";
    else {
        for (int i = 0; i < res.size(); i++)
            ofile << res[i] << endl;
    }

    ifile.close();
    ofile.close();
    return 0;
}