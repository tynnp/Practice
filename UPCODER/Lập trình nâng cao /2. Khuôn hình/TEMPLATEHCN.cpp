#include <iostream>
#include <iomanip>
using namespace std;

struct HCN {
    double dai, rong;

    friend istream& operator >> (istream &in, HCN &hcn) {
        in >> hcn.dai >> hcn.rong;
        return in;
    } 

    friend ostream& operator << (ostream &out, HCN hcn) {
        out << "[HCN] " << hcn.dai << "," << hcn.rong;
        return out;
    }

    double chuVi() {
        return (double) (dai + rong) * 2;
    }

    bool operator < (HCN other) {
        return chuVi() < other.chuVi();
    }

    double operator + (double n) {
        return chuVi() + n;
    }
};

bool operator == (HCN hcn, int n) {
    return true;
}

template <typename T>
struct Array {
    int size = 0;
    T values[1000];

    friend istream& operator >> (istream &in, Array &arr) {
        T n; 
        while (in >> n)
            arr.values[arr.size++] = n;
        return in;
    }

    T min() {
        T res = values[0];
        for (int i = 1; i < size; i++)
            if (values[i] < res)
                res = values[i];
        return res;
    }

    double sum() {
        double res = 0;
        for (int i = 0; i < size; i++)
            res = values[i] + res;
        return res; 
    }
};

template<typename T> 
void check(char c) {
    Array<T> arr;
    cin >> arr;
    cout << arr.min() << endl;
    if (c == 'H') cout << fixed << setprecision(1);
    cout << arr.sum();
    return;
}

int main() {
    char c; 
    cin >> c;
    
    switch (c) {
        case 'N': check<int>('N'); break;
        case 'H': check<HCN>('H'); break;
    }

    return 0;
}