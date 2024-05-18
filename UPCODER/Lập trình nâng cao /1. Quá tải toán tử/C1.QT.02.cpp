#include <iostream>
using namespace std;

struct SoPhuc {
    int thuc, ao;
};

istream& operator >> (istream &in, SoPhuc &sp) {
    in >> sp.thuc >> sp.ao;
    return in;
}

ostream& operator << (ostream &out, SoPhuc sp) {
    if (sp.thuc != 0) out << sp.thuc;

    if (sp.ao != 0) {
        if (sp.ao > 0 && sp.thuc != 0) out << "+";
        if (sp.ao < 0) out << "-";
        out << abs(sp.ao) << "*i";
    } 
        
    return out;
}

SoPhuc operator + (SoPhuc a, SoPhuc b) {
    SoPhuc res;
    res.thuc = a.thuc + b.thuc;
    res.ao = a.ao + b.ao;
    return res;
}

SoPhuc operator - (SoPhuc a, SoPhuc b) {
    SoPhuc res;
    res.thuc = a.thuc - b.thuc;
    res.ao = a.ao - b.ao;
    return res;
}

SoPhuc operator * (SoPhuc a, SoPhuc b) {
    SoPhuc res;
    res.thuc = a.thuc*b.thuc - a.ao*b.ao;
    res.ao = a.thuc*b.ao + a.ao*b.thuc;
    return res;
}

bool operator < (SoPhuc a, SoPhuc b) {
    if (a.thuc < b.thuc) return true;
    else if (a.thuc == b.thuc) 
        if (a.ao < b.ao) return true;
    return false;
}

int main() {
    int n; 
    cin >> n;

    SoPhuc arr[n];
    for (SoPhuc &x : arr) cin >> x;

    SoPhuc lonNhat = arr[0], nhoNhat = arr[0];
    SoPhuc tong = arr[0], tich = arr[0];

    for (int i = 1; i < n; i++) {
        if (lonNhat < arr[i]) lonNhat = arr[i];
        if (arr[i] < nhoNhat) nhoNhat = arr[i];
        tong = tong + arr[i];
        tich = tich * arr[i];
    }
    
    cout << lonNhat << endl;
    cout << tong << endl;
    cout << tich << endl;
    cout << lonNhat - nhoNhat;

    return 0;
}