#include <fstream>
using namespace std;

int dem(string s1, string s2) {
    int cnt = 0;
    if (s2.find(s1) == string::npos) return cnt;

    auto index = s2.find(s1, 0);
    while (index != string::npos) {
        cnt += 1;
        index = s2.find(s1, index+1);
    }

    return cnt;
}

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("chuoi.inp");
    fout.open("chuoi.out");

    string s1, s2;
    getline(fin, s1);
    getline(fin, s2);

    int cnt = dem(s1, s2);  
    if (cnt == 0) fout << "NOT FOUND";
    else fout << "FOUND" << endl << cnt;

    fin.close();
    fout.close();
    return 0;
}