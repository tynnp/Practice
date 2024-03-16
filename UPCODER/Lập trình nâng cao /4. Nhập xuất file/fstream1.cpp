#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream ifile; 
    ifile.open("input.txt");

    int a, b;
    ifile >> a >> b;
    cout << a + b;

    ifile.close();
    return 0;
}