#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream ifile; 
    ofstream ofile; 
    ifile.open("input.txt");
    ofile.open("output.txt");

    int a, b; 
    ifile >> a >> b;
    ofile << a + b;

    ifile.close();
    ofile.close();
    return 0;
}