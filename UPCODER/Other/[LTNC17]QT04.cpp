#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("DAYSO.INP");
    fout.open("DAYSO.OUT");

    int fib[30];
    int tmp, max = 1;
    vector<bool> checkFib(1000000, false);
    vector<int> vt, vtFib;

    fib[1] = fib[2] = 1;

    for (int i = 3; i < 30; i++)
        fib[i] = fib[i-1] + fib[i-2];

    for (int i = 1; i < 30; i++)
        checkFib[fib[i]] = true;

    
    while (fin >> tmp) {
        vt.push_back(tmp);
        if (checkFib[tmp]) {
            vtFib.push_back(tmp);
            if (max < tmp) max = tmp;
        }
    }

    for (int x : vtFib)     
        fout << x << " ";
    fout << endl;

    fout << max << " ";
    for (int i = 1; i < 30; i++)
        if (fib[i] == max) fout << i;

    fin.close();
    fout.close();
    return 0;
}