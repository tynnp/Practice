#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, maxGiaTri = 0;
    cin >> n;

    vector<int> giaTri(n);
    for (auto &gt : giaTri) {
        cin >> gt;
        maxGiaTri = max(maxGiaTri, gt);
    }

    int demCap = 0;
    vector<int> daTham(maxGiaTri + 1);
    for (int i = 0; i < n; i++) {
        vector<int> daXem(maxGiaTri + 1);
        bool timThay = false;

        for (int j = i + 1; j < n; j++) {
            if (giaTri[i] > giaTri[j] && daTham[giaTri[i]] == 0 && daXem[giaTri[j]] == 0) {
                demCap++;
                timThay = true;
                daXem[giaTri[j]] = 1;
            }
        }

        if (timThay) daTham[giaTri[i]] = 1;
    }

    cout << demCap;
    return 0;
}
