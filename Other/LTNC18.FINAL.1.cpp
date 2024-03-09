#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;

bool checkCP(int n) {
    return (int) sqrt(n) == sqrt(n);
}

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("MANGDONG.INP");
    fout.open("MANGDONG.OUT");

    int n, k, cnt = 0;
    bool check = false;
    fin >> n >> k;

    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        fin >> arr[i];
        if (checkCP(arr[i])) cnt++;
        if (arr[i] == k) check = true;
    }

    sort(arr, arr + n);

    fout << cnt << endl;
    fout << (check ? "Yes" : "No") << endl;
    for (int i = 0; i < n; i++) 
        if (!checkCP(arr[i])) 
            fout << arr[i] << " ";

    fin.close();
    fout.close();
    return 0;
}
