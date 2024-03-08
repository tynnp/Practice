#include <fstream>
#include <bitset>
using namespace std;

string hexToOct(string hexNum) {
    int decNum = stoi(hexNum, nullptr, 16);
    string octNum = "";

    while (decNum != 0) {
        octNum = to_string(decNum % 8) + octNum;
        decNum /= 8;
    }
    
    return octNum;
}

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("coso.inp");
    fout.open("coso.out");

    string hexNum;
    fin >> hexNum;
    fout << hexToOct(hexNum);

    fin.close();
    fout.close();
    return 0;
}