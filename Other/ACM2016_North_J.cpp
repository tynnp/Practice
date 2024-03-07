#include<iostream>
#include<cmath>

using namespace std;
int main() {
    int n; 
    long long a;

    cin >> n;
    while (n--) {
        cin >> a;
        if(a == 0 || a < 1000) cout << "1" << endl; 
        else if (a == 1000 || a < 3000) cout << "2" << endl; 
        else if (a == 3000 || a < 6000) cout << "3" << endl;  
        else if (a == 6000 || a < 10000) cout << "4" << endl;  
        else if (a == 10000 || a < 15000) cout << "5" << endl;  
        else if (a == 15000 || a < 21000) cout << "6" << endl;  
        else if (a == 21000 || a < 28000) cout << "7" << endl;  
        else if (a == 28000 || a < 36000) cout << "8" << endl;  
        else if (a == 36000 || a < 45000) cout << "9" << endl;  
        else if (a == 45000 || a < 55000) cout << "10" << endl; 
        else if (a == 55000 || a < 65000) cout << "11" << endl; 
        else if (a == 65000 || a < 75000) cout << "12" << endl; 
        else if (a == 75000 || a < 85000) cout << "13" << endl; 
        else if (a == 85000 || a < 100000) cout << "14" << endl; 
        else if (a == 100000 || a < 120000) cout << "15" << endl; 
        else if (a == 120000 || a < 140000) cout << "16" << endl; 
        else if (a == 140000 || a < 160000) cout << "17" << endl; 
        else if (a == 160000 || a < 185000) cout << "18" << endl; 
        else if (a == 185000 || a < 210000) cout << "19" << endl; 
        else if (a == 210000 || a < 260000) cout << "20" << endl; 
        else if (a == 260000 || a < 335000) cout << "21" << endl; 
        else if (a == 335000 || a < 435000) cout << "22" << endl; 
        else if (a == 435000 || a < 560000) cout << "23" << endl; 
        else if (a == 560000 || a < 710000) cout << "24" << endl; 
        else if (a == 710000 || a < 900000) cout << "25" << endl; 
        else if (a == 900000 || a < 1100000) cout << "26" << endl; 
        else if (a == 1100000 || a < 1350000) cout << "27" << endl; 
        else if (a == 1350000 || a < 1650000) cout << "28" << endl; 
        else if (a == 1650000 || a < 2000000) cout << "29" << endl; 
        else if (a == 2000000 || a < 2500000) cout << "30" << endl; 
        else if (a == 2500000 || a < 3000000) cout << "31" << endl; 
        else if (a == 3000000 || a < 3750000) cout << "32" << endl; 
        else if (a == 3570000 || a < 4750000) cout << "33" << endl; 
        else if (a == 4750000 || a < 6000000) cout << "34" << endl; 
        else if (a == 6000000 || a < 7500000) cout << "35" << endl; 
        else if (a == 7500000 || a < 9500000) cout << "36" << endl; 
        else if (a == 9500000 || a < 12000000) cout << "37" << endl; 
        else if (a == 12000000 || a < 15000000) cout << "38" << endl; 
        else if (a == 15000000 || a < 20000000) cout << "39" << endl; 
        else if (a == 20000000 || a > 20000000) cout << "40" << endl; 
    }

    return 0;
}