#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int a, b;
    ifstream f;

    f.open("input.txt");
    f >> a >> b;
    f.close();

    cout << a + b;
    
    return 0;
}