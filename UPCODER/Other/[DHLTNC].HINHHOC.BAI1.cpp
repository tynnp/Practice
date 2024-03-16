#include <iostream>
#include <cmath>
using namespace std;
 
struct ToaDo {
    int x; 
    int y;
    friend istream& operator >> (istream& in, ToaDo& td) {
        in >> td.x >> td.y;
    }
};

double khoangCach(ToaDo td1, ToaDo td2) {
    return sqrt(pow(td2.x - td1.x, 2) + pow(td2.y - td1.y, 2));
}

bool check(double d1, double d2, double d3) {
    return (d1 + d2 > d3 && d1 + d3 > d2 && d2 + d3 > d1);
}

int main() {
    ToaDo a, b, c; cin >> a >> b >> c;
    double d1 = khoangCach(a, b);
    double d2 = khoangCach(a, c);
    double d3 = khoangCach(b, c);
    if (check(d1, d2, d3)) cout << "YES";
    else cout << "NO"; 
    return 0;
}