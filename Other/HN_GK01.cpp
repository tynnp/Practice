#include <iostream>
#include <fstream>
using namespace std;

bool checkNguyenTo(int n) {
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return n > 1;
}

bool checkSoDep(int n) {
    int res = 0;
    while (n > 0) 
        res += n%10, n /= 10;
    return res%10 == 7;
}

int tongChuSoNguyenTo(int n) {
    int res = 0;
    while (n > 0) {
        if (checkNguyenTo(n % 10)) 
            res += n % 10;
        n /= 10; 
    }
    return res;
}

int tichChuSo(int n) {
    int res = 1;
    while (n > 0) 
        res *= n%10, n /= 10;
    return res;
}

int main() {
    ifstream ifile;
    ofstream ofile;
    ifile.open("input.txt");
    ofile.open("output.txt");

    int n;
    while (ifile >> n) {
        if (checkSoDep(n)) ofile << tichChuSo(n);
        else ofile << tongChuSoNguyenTo(n);
        ofile << endl;
    }

    ifile.close();
    ofile.close();
    return 0;
}