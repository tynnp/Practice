#include <fstream>
#include <algorithm>
#include <cctype>
using namespace std;

bool check(string s) {
    s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    int size = s.size();
    
    for (int i = 0; i < size/2; i++)
        if (s[i] != s[size - i - 1])
            return false;
    
    return true;
}

int main() {
    string str;
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    
    while (getline(fin, str))
        fout << check(str) << endl;
        
    fin.close();
    fout.close();
    return 0;
}

