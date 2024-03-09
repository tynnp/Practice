#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<int> &arr, int &num) {
    int l = 0, r = arr.size()-1;

    while (l <= r) {
        int mid = (l + r) >> 1;
        if (arr[mid] == num) return true;
        else if (arr[mid] < num) l = mid + 1;
        else r = mid - 1;
    }

    return false;
}

int main() {
    ifstream fin("COUNT.INP");
    ofstream fout("COUNT.OUT");

    int n, m;
    fin >> n >> m;
    
    vector<int> arr(n);
    for (int &x : arr) fin >> x;
    sort(arr.begin(), arr.end());

    int tmp, cnt = m;
    while (m--) {
        fin >> tmp;
        cnt -= check(arr, tmp);
    }
    
    fout << cnt;
    fin.close();
    fout.close();
    return 0;
}