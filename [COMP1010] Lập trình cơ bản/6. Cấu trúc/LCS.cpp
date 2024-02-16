#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

struct TinhDiem {
    string tenDoi;
    int like, cmt, share;
};

bool check(TinhDiem a, TinhDiem b) {
    int diemA = a.like + a.cmt*2 + a.share*3;
    int diemB = b.like + b.cmt*2 + b.share*3;
    return diemA > diemB;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TinhDiem list[100];
    int size = 0;

    while (cin >> list[size].tenDoi >> list[size].like >>
    list[size].cmt >> list[size].share) size++;

    sort(list, list + size, check);

    for (int i = 0; i < 3; i++)
        cout << list[i].tenDoi << endl;

    return 0;
}