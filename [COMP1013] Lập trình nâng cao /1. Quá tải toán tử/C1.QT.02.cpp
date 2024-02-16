#include <iostream>
using namespace std;

struct SoPhuc {
    int thuc;
    int ao;

    friend istream& operator >> (istream &in, SoPhuc &sp) {
        in >> sp.thuc >> sp.ao;
        return in;
    }

    friend ostream& operator << (ostream &out, SoPhuc sp) {
        if (sp.thuc != 0) out << sp.thuc;

        if (sp.ao != 0) {
            if (sp.ao > 0 && sp.thuc != 0) out << "+";
            if (sp.ao < 0) out << "-";
            out << abs(sp.ao) << "*i";
        } 
        
        return out;
    }

    SoPhuc operator + (SoPhuc sp) {
        SoPhuc res;
        res.thuc = this->thuc + sp.thuc;
        res.ao = this->ao + sp.ao;
        return res;
    }

    SoPhuc operator - (SoPhuc sp) {
        SoPhuc res;
        res.thuc = this->thuc - sp.thuc;
        res.ao = this->ao - sp.ao;
        return res;
    }

    SoPhuc operator * (SoPhuc sp) {
        SoPhuc res;
        res.thuc = this->thuc*sp.thuc - this->ao*sp.ao;
        res.ao = this->thuc*sp.ao + this->ao*sp.thuc;
        return res;
    }

    bool operator < (SoPhuc sp) {
        if (this->thuc < sp.thuc) return true;
        else if (this->thuc == sp.thuc) 
            if (this->ao < sp.ao) return true;
        return false;
    }

};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
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