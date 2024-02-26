#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream ifile;
    ofstream ofile;
    ifile.open("input.txt");
    ofile.open("output.txt");

    int n;
    ifile >> n;

    int arr[n];
    for (int &x : arr) ifile >> x;
    for (int x : arr) ofile << x << endl;

    ifile.close();
    ofile.close();
    return 0;
}