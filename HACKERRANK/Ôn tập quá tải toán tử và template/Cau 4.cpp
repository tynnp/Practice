#include <iostream>
using namespace std;

struct LopHoc {
    int maLop, siSo;
};

istream &operator >> (istream &in, LopHoc &obj) {
    in >> obj.maLop >> obj.siSo;
    return in;
}

ostream &operator << (ostream &out, LopHoc obj) {
    out << obj.siSo;
    return out;
}

int operator + (LopHoc a, LopHoc b) {
    return a.siSo + b.siSo;
}

bool operator > (LopHoc a, LopHoc b) {
    return a.siSo > b.siSo;
}

bool operator == (LopHoc a, LopHoc b) {
    return a.siSo == b.siSo;
}

template <typename T>
void run() {
    T arr[100];
    int n(0), cnt(1);

    while (cin >> arr[n]) n++;
    T res = arr[0];

    for (int i = 1; i < n; i++)
        if (arr[i] > res) res = arr[i], cnt = 1;
        else if (arr[i] == res) cnt++;

    cout << res << endl << cnt;
}

int main() {
    char kt;
    cin >> kt;

    switch (kt) {
        case 'a': run<int>(); break;
        case 'b': run<LopHoc>(); break;
    }

    return 0;
}