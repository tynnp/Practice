#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int a, b; 
    cin >> a >> b;

    ofstream file; 
    file.open("out.txt");
    
    file << a + b;
    file.close();
    return 0;
}