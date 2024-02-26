#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
 
struct ToaDo {
    int x; 
    int y;

    friend istream& operator >> (istream& in, ToaDo& td) {
        in >> td.x >> td.y;
    }
};

double khoangCach(ToaDo a, ToaDo b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

int main() {
    ToaDo a, b, c;
    cin >> a >> b >> c;
    double AB = khoangCach(a, b);
    double BC = khoangCach(b, c);
    double AC = khoangCach(a, c);
    double CV = AB + BC + AC;
    double P = CV / 2;
    if (AB + BC > AC && AB + AC > BC && BC + AC > AB) 
        cout << "YES\n" << fixed << setprecision(5) << sqrt(P*(P-AB)*(P-AC)*(P-BC));
    else cout << "NO";
    return 0;
}