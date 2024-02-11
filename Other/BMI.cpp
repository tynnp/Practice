#include <iostream>
#include <iomanip>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    double cao, nang, bmi;
    cin >> cao >> nang;
    bmi = nang / (cao*cao);

    cout << fixed << setprecision(2);
    cout << "Chi so BMI: " << bmi << endl;
    cout << "Ket qua: ";

    if (bmi < 18.5) cout << "gay";
    else if (bmi < 25) cout << "binh thuong";
    else if (bmi >= 25) cout << "thua can";
    
    return 0;
}