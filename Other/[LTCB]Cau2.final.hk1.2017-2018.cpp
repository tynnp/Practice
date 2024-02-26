#include <iostream>
using namespace std;
 
int main() {
    int n, sobit_0 = 0; 
    string str; 
    cin >> n >> str;
    int lien_tiep = 0, k = 0; 
    
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '1') k++;
        if (str[i] == '0') sobit_0++;
        if (str[i] != str[i+1]) {
            if (lien_tiep < k) lien_tiep = k; 
            k = 0;
        }
    }

    cout << sobit_0 << " " << n - sobit_0 << endl << lien_tiep;
    return 0;
}