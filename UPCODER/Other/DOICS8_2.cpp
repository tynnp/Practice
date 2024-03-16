#include <fstream>
#include <bitset>
using namespace std;

string octToBinary(string octNum) {
    int decNum = stoi(octNum, nullptr, 8);
    string binaryNum = bitset<32>(decNum).to_string();
    binaryNum.erase(0, binaryNum.find_first_not_of('0'));
    return binaryNum;
}

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("coso.inp");
    fout.open("coso.out");

    string octNum;
    fin >> octNum;
    fout << octToBinary(octNum);

    fin.close();
    fout.close();
    return 0;
}
