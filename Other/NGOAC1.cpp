#include <iostream>
using namespace std;
 
int main() {
    string str; 
    cin >> str;
    int dem_mo = 0, dem_dong = 0;

    for (int i = 0; i < str.size(); i++) 
        (str[i] == '(') ? dem_mo++ : dem_dong++;

    if (str[0] == ')' || str[str.size() - 1] == '(')
        cout << "FALSE";
    else 
        cout << (dem_mo == dem_dong ? "TRUE" : "FALSE");
        
    return 0;
}