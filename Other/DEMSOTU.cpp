#include <iostream>
using namespace std;
 
int main() {
    string str; 
    getline(cin, str);
    int cnt_chu = 0;
    int cnt_so = 0;

    for (char c : str) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) cnt_chu++;
        if (c >= '0' && c <= '9') cnt_so++;
    }
    
    cout << "so chu cai la: " << cnt_chu << endl;
    cout << "so chu so la: " << cnt_so << endl;
    return 0;
}