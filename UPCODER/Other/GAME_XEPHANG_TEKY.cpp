#include <iostream>
using namespace std;
 
int main() {
    int VVang, VBac, VDong, TVang, TBac, TDong, cach;
    cin >> VVang >> VBac >> VDong;
    cin >> TVang >> TBac >> TDong;
    cin >> cach;
    int Vtong = VVang + VBac + VDong;
    int Ttong = TVang + TBac + TDong;

    if (cach == 1) {
        if (Vtong > Ttong) cout << "Python vo dich";
        else if (Vtong < Ttong) cout << "MakeCode vo dich";
        else cout << "Hoa";
    } else if (cach == 2) {
        if ((VVang > TVang) || (VVang == TVang && VBac > TBac) || (VVang == TVang && VBac == TBac && VDong > TDong)) cout << "Python vo dich" << endl;
        else if (VVang == TVang && VBac == TBac && VDong == TDong) cout << "Hoa";
        else cout << "MakeCode vo dich";
    }
    
    return 0;
}