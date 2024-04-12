#include <iostream>
#include <cmath>
#define PI 3.14159
using namespace std;

struct ToaDo {
    int x, y;

    float doDaiVoi(ToaDo other) {
        return sqrt(pow(other.x-x, 2) + pow(other.y-y, 2));
    }
};

istream &operator >> (istream &cin, ToaDo &td) {
    cin >> td.x >> td.y;
    return cin;
}

bool operator == (ToaDo a, ToaDo b) {
    return a.x == b.x && a.y == b.y;
}

struct VoiPhun {
    ToaDo O;
    int R;

    float dienTich() {
        return PI*R*R;
    }

    float doDaiVoi(VoiPhun other) {
        return O.doDaiVoi(other.O);
    }
}; 

istream &operator >> (istream &cin, VoiPhun &vp) {
    cin >> vp.O >> vp.R;
    return cin;
}

ostream &operator << (ostream &cout, VoiPhun vp) {
    cout << "(x";
    if (vp.O.x < 0) cout << '+' << abs(vp.O.x);
    else cout << '-' << vp.O.x;

    cout << ")^2+(y";
    if (vp.O.y < 0) cout << '+' << abs(vp.O.y);
    else cout << '-' << vp.O.y;

    cout << ")^2=";
    cout << vp.R*vp.R << endl;
    return cout;
}

float operator + (VoiPhun a, VoiPhun b) {
    return round((a.dienTich() + b.dienTich()) * 1000.0F) / 1000.0F;
}

float operator - (VoiPhun a, VoiPhun b) {
    return a.doDaiVoi(b) ;
}

string operator == (VoiPhun a, VoiPhun b) {
    if (a.O == b.O && a.R == b.R) return "A trung voi B";
    else return "A khong trung voi B";
}

string operator < (VoiPhun a, VoiPhun b) {
    if (a.dienTich() < b.dienTich()) return "A nho hon B";
    else return "A khong nho hon B";
}

string operator > (VoiPhun a, VoiPhun b) {
    if (a.dienTich() > b.dienTich()) return "A lon hon B";
    else return "A khong lon hon B";
}

bool operator & (VoiPhun a, VoiPhun b) {
    return a.R + b.R > a - b;
}

float dienTichTrung(VoiPhun a, VoiPhun b) {
    float r1 = a.R, r2 = b.R; 
    float d = a - b;
    float d1 = (r1*r1 - r2*r2 + d*d) / (2.0*d); 
    float d2 = d - d1;
    return r1*r1*acos(d1/r1) - d1*sqrt(r1*r1 - d1*d1) + r2*r2*acos(d2/r2) - d2*sqrt(r2*r2 - d2*d2);
} 

void xuatViTri(int i, int j) {
    cout << "(" << i << "," << j << ") ";
}

int main() {
    int n;
    VoiPhun a, b;
    float dienTichPhun = 0, tongDienTich = 0;

    cin >> a >> b >> n;
    cout << (a & b ? "A chong lap B" : "A khong chong lap B") << endl;

    VoiPhun list[n]; 
    for (VoiPhun &x : list) cin >> x;
    
    for (int i = 0; i < n; i++) 
        for (int j = i+1; j < n; j++) 
            if (list[i] & list[j]) xuatViTri(i+1, j+1);
    cout << endl;

    for (int i = 1; i < n; i++) 
        dienTichPhun += list[i-1] + list[i] - dienTichTrung(list[i-1], list[i]),
        tongDienTich += list[i-1] + list[i];
    cout << dienTichPhun ;
    
    return 0;
}