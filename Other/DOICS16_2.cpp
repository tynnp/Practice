#include <fstream>
#include <bitset>
using namespace std;

string hexToBinary(string hexNum) {
    int decNum = stoi(hexNum, nullptr, 16);
    string binaryNum = bitset<32>(decNum).to_string();
    binaryNum.erase(0, binaryNum.find_first_not_of('0'));
    return binaryNum;
}

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("coso.inp");
    fout.open("coso.out");

    string hexNum;
    fin >> hexNum;
    fout << hexToBinary(hexNum);

    fin.close();
    fout.close();
    return 0;
}