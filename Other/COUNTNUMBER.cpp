#include <iostream>
#include <vector>
using namespace std;

vector<int> demDuong(1000005, 0);
vector<int> demAm(1000005, 0);
vector<int> mang(1000005);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, i = 0;
    cin >> n;

    for (i = 0; i < n; i++) 
        cin >> mang[i];
    
    for (i = 0; i < n; i++) {
        if (mang[i] > 0) demDuong[mang[i]]++;
        else demAm[-mang[i]]++;
    }

    for (i = 0; i < n; i++) {
        if (mang[i] > 0) {
            if (demDuong[mang[i]] != 0) {
                cout << demDuong[mang[i]] << ' ';
                demDuong[mang[i]] = 0;
            }

        } else {
            if (demAm[-mang[i]] != 0) {
                cout << demAm[-mang[i]] << ' ';
                demAm[-mang[i]] = 0;
            }
        }
    }
    
    return 0;
}
