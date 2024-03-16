#include <iostream>
#include <cmath>
#define MAX 99999999
#define MIN -99999999
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;

int arr[10000], n = 0;
bool SNT(int a);
int UCLN(int a, int b);
void Dong_1(int max);
void Dong_2(int min);
void Dong_3();
void Dong_4();

int main() {
    int max = MIN, min = MAX;

    while (cin >> arr[n]) {
        if (max < arr[n]) max = arr[n];
        if (min > arr[n]) min = arr[n];
        n += 1;
    } 

    Dong_1(max); 
    Dong_2(min); 
    Dong_3(); 
    Dong_4();
    return 0;
}

bool SNT(int a) {
    for (int i = 2; i <= sqrt(a); i++)
        if (a % i == 0) return false;
    return a > 1;
}

int UCLN(int a, int b) {
    if (b == 0) return a;
    return UCLN(b, a % b);
}

void Dong_1(int max) {
    int max_nhi = MIN, vi_tri = -1;
    FOR(i, 0, n) 
        if (max_nhi <= arr[i] && arr[i] < max)
            max_nhi = arr[i], vi_tri = i;
    cout << vi_tri << endl;
}

void Dong_2(int min) {
    int min_nhi = MAX, k = 0;
    FOR(i, 0, n)
        if (min_nhi > arr[i] && arr[i] > min)
            min_nhi = arr[i];
    FOR(i, 0, n)
        if (min_nhi == arr[i])
            cout << i << " ", k++;
    if (!k) cout << -1;
    cout << endl;
}

void Dong_3() {
    int gcd = -1;
    FOR(i, 0, n-1) FOR(j, i+1, n)
        gcd = max(gcd, UCLN(arr[i], arr[j]));
    cout << gcd << endl;
}

void Dong_4() {
    int NNNN = MAX;
    FOR(i, 0, n-1) FOR(j, i+1, n)
        if (SNT(arr[i] + arr[j]))
            NNNN = min(NNNN, arr[i] + arr[j]);
    cout << (NNNN == MAX ? -1 : NNNN);
}