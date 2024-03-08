#include <fstream>
#include <bitset>
using namespace std;

int hexToDec(string hexNum) {
    return stoi(hexNum, nullptr, 16);
}

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("coso.inp");
    fout.open("coso.out");

    string hexNum;
    fin >> hexNum;
    fout << hexToDec(hexNum);

    fin.close();
    fout.close();
    return 0;
}