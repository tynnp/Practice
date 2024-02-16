#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define endl '\n'
using namespace std;

struct DaThuc {
    int size;
    vector<int> giaTri;

    DaThuc(int size, int x) {
        this->size = size;
        giaTri = vector<int> (size + 1, x);
    }

    void nhap() {
        for (int i = 0; i <= size; i++)
            cin >> giaTri[i];
        return;
    }

    int giaTriOf(int x) {
        int res = 0;
        for (int i = 0; i <= size; i++)
            res += giaTri[i] * pow(x, size-i);
        return res;
    }

    bool operator < (DaThuc f2) {
        if (size < f2.size) return true;
        else if (size == f2.size) {
            for (int i = 0; i <= size; i++) 
                if (giaTri[i] < f2.giaTri[i]) return true;
        }
        return false;
    }

    vector<DaThuc> phanTich() {
        vector<DaThuc> res;
        for (int i = -10; i <= 10; i++) {
            if (giaTriOf(i) == 0 && size > 1) {
                DaThuc tmp(1, 1); tmp.giaTri[1] = -i;
                res.push_back(tmp);

                for (int j = 1; j <= size; j++)
                    giaTri[j] = i*giaTri[j-1] + giaTri[j];
                size--;
            }
        }
        res.push_back(*this);
        sort(res.begin(), res.end());
        return res;
    }

    void xuat() {
        for (int i = 0; i <= size; i++) {
            if (giaTri[i] == 0) continue;

            if (i != 0 && giaTri[i] > 0) cout << "+";
            else if (giaTri[i] < 0) cout << "-";

            if (abs(giaTri[i]) != 1) cout << abs(giaTri[i]);
            else if (i == size) cout << abs(giaTri[i]);

            if (i < size-1) cout << "x^" << size-i;
            else if (i == size-1) cout << "x";
        }
        return;
    }
}; 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int size; cin >> size;
    DaThuc daThuc(size, 0);

    daThuc.nhap();
    daThuc.xuat();
    cout << "=";

    vector<DaThuc> res = daThuc.phanTich();
    for (int i = 0; i < res.size(); i++) {
		if (res[i].size == 1 && res[i].giaTri[1] == 0) 
            res[i].xuat();
		else {
			cout << "("; 
            res[i].xuat();
            cout << ")";
        }
	}

    return 0;
}