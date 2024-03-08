#include <fstream>
#include <iostream>
using namespace std;

int octToDecimal(string octNum) {
    return stoi(octNum, nullptr, 8);
}

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("coso.inp");
    fout.open("coso.out");

    string octNum;
    fin >> octNum;
    fout << octToDecimal(octNum);

    fin.close();
    fout.close();
    return 0;
}
