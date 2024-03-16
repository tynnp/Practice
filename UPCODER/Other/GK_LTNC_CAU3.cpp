#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool soCP(const int n) {
    return ((int) sqrt(n)*sqrt(n) == n);
}

void sapXepVector(vector<int> &v) {
    for (int i = 1; i < v.size(); i++) {
        int j = i;
        while (j > 0 && v[j-1] >= v[j]) 
            swap(v[j-1], v[j]), j--;
    }
}

void nhapVector(vector<int> &v, int x) {
    for (int i = 0; i < x; i++) cin >> v[i];
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++) 
        if (it != v.end() && soCP(*it)) v.erase(it--);
}

void hoiVector(vector<int> a, vector<int> b) {
    vector<int> res;
    for (int x : a) res.push_back(x);
    for (int x : b) res.push_back(x);
    sapXepVector(res);
    for (int x : res) cout << x << " "; cout << endl;
}

void giaoVector(vector<int> a, vector<int> b) {
    vector<int> res;
    for (int i = 0; i < a.size(); i++) {
        vector<int>::iterator it; 
        it = find(b.begin(), b.end(), a[i]);
        if (it != b.end()) res.push_back(a[i]);
    }
    sapXepVector(res);
    for (int x : res) cout << x << " ";
}

int main() {
    int n, m; 
    cin >> n >> m;
    vector<int> vt1(n), vt2(m);
    nhapVector(vt1, n);
    nhapVector(vt2, m);
    hoiVector(vt1, vt2);
    giaoVector(vt1, vt2);
    return 0;
}