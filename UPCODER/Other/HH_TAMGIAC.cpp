#include <iostream>
#include <fstream>
using namespace std;

string check(double a, double b, double c) {
    if (a*a + b*b < c*c || a*a + c*c < b*b || b*b + c*c < a*a || a <= 0 || b <= 0 || c <= 0) return "impossible";
    if (a == b && a == c) return "DEU";
    else if ((a == b || b == c || a == c) && (a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a)) return "VUONGCAN";
    else if (a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a) return "VUONG";
    else if (a == b || b == c || a == c) return "CAN";
    else return "THUONG";
}

int main() {
    ifstream ifile;
    ofstream ofile;
    ifile.open("TAMGIAC.INP");
    ofile.open("TAMGIAC.OUT");
    double a, b, c; 
    bool checkEND = false;

    while (ifile >> a >> b >> c) {
        if (checkEND) ofile << endl;
        ofile << check(a, b, c);
        if (check(a, b, c) != "impossible")
             ofile << " " << a << " " << b << " " << c;
        checkEND = true;
    }
    
    ifile.close();
    ofile.close();
    return 0;
}