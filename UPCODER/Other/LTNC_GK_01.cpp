#include <iostream>
#include <fstream>
using namespace std;
 
bool soNguyenTo(int n) {
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return n > 1; 
}

int main() {
    ifstream ifile;
    ofstream ofile;
    ifile.open("INPUT.txt");
    ofile.open("OUTPUT.TXT");

    int n; 
    ifile >> n; 
    ofile << (soNguyenTo(n) ? "YES" : "NO");

    ifile.close();
    ofile.close();
    return 0;
}