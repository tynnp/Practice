#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct PhanSo {
    int tu, mau;
    PhanSo(): tu(0), mau(0) {}

    friend istream& operator >> (istream &in, PhanSo &p) {
        string str; in >> str;
        int index = 0;

        for (index; index < str.length(); index++) {
            if (str[index] == '/') break;
            p.tu = p.tu*10 + str[index] - 48;
        }

        for (++index; index < str.length(); index++) {
            if (str[index] == '/') break;
            p.mau = p.mau*10 + str[index] - 48;
        }

        return in;
    }

    friend ostream& operator << (ostream &out, PhanSo p) {
        int ucln = __gcd(p.tu, p.mau);
        p.tu /= ucln;
        p.mau /= ucln;

        out << p.tu;
        if (p.tu != 0 && p.mau != 1)
            out << "/" << p.mau;

        return out;
    }

    bool operator == (PhanSo other) {
        return this->tu*other.mau == this->mau*other.tu;
    }

    bool operator < (PhanSo other) {
        return (double) this->tu/this->mau < (double) other.tu/other.mau;
    }

    bool operator > (PhanSo other) {
        return (double) this->tu/this->mau > (double) other.tu/other.mau;
    }

    PhanSo operator + (PhanSo other) {
        PhanSo res;
        res.tu = this->tu*other.mau + this->mau*other.tu;
        res.mau = this->mau * other.mau;
        
        int ucln = __gcd(res.tu, res.mau);
        res.tu /= ucln, res.mau /= ucln;

        return res;
    }
};

template <typename T>
struct Array {
    int size;
    T *values;

    friend istream& operator >> (istream &in, Array &arr) {
        in >> arr.size;
        arr.values = new T[arr.size];

        for (int i = 0; i < arr.size; i++)
            in >> arr.values[i];

        return in;
    }

    friend ostream& operator << (ostream &out, Array arr) {
        for (int i = 0; i < arr.size; i++)
            out << arr.values[i] << " ";
        return out;
    }

    T tongPhanTu() {
        T res = this->values[0];
        for (int i = 1; i < this->size; i++)
            res = res + this->values[i];
        return res;
    }  
    
    T phanTuMax() {
        T res = this->values[0];
        for (int i = 1; i < this->size; i++)
            if (res < this->values[i])
                res = this->values[i];
        return res;
    }
};

template<typename T>
Array<T> operator + (Array<T> arr1, Array<T> arr2) {
    Array<T> res, max, min;

    if (arr1.size < arr2.size) 
        max = arr2, min = arr1;
    else 
        max = arr1, min = arr2;

    res.size = max.size;
    res.values = new T[res.size];

    for (int i = 0; i < min.size; i++)
        res.values[i] = max.values[i] + min.values[i];
    for (int i = min.size; i < max.size; i++)
        res.values[i] = max.values[i];

    return res;
}

Array<int> sapXep(Array<int> arr, char c = '<') {
    if (c == '<') {
        sort(arr.values, arr.values + arr.size, [] (int a, int b) {
            if (a % 2 == 0 && b % 2 != 0) return true;
            if (a % 2 != 0 && b % 2 == 0) return false;
            return a < b;
        });

    } else if (c == '>') {
        sort(arr.values, arr.values + arr.size, [] (int a, int b) {
            if (a % 2 != 0 && b % 2 != 0) return a > b;
            if (a % 2 == 0 && b % 2 == 0) return a > b;
            return a % 2 != 0;
        });
    }
    return arr;
}

Array<PhanSo> sapXep(Array<PhanSo> arr, char c = '<') {
    if (c == '<') {
        for (int i = 1; i < arr.size; i++) {
            int j = i;
            while (j > 0 && arr.values[j-1] > arr.values[j]) {
                swap(arr.values[j-1], arr.values[j]);
                j--;
            }
        }
    } else if (c == '>') {
        for (int i = 1; i < arr.size; i++) {
            int j = i;
            while (j > 0 && arr.values[j-1] < arr.values[j]) {
                swap(arr.values[j-1], arr.values[j]);
                j--;
            }
        }
    }
    return arr;
}

int main() {
    char c; cin >> c;
    Array<int> arrInt1;
    Array<int> arrInt2;
    Array<PhanSo> arrPhanSo1;
    Array<PhanSo> arrPhanSo2;

    if (c == 'I') {
        cin >> arrInt1 >> arrInt2;
        Array<int> sum = arrInt1 + arrInt2;

        cout << arrInt1 << endl;
        cout << "MAX 1 = " << arrInt1.phanTuMax() << endl;
        cout << "SUM 1 = " << arrInt1.tongPhanTu() << endl;
        Array<int> res1 = sapXep(arrInt1); cout << res1 << endl;

        cout << arrInt2 << endl;
        cout << "MAX 2 = " << arrInt2.phanTuMax() << endl;
        cout << "SUM 2 = " << arrInt2.tongPhanTu() << endl;
        Array<int> res2 = sapXep(arrInt2, '>'); cout << res2 << endl;
    
        cout << sum;

    } else if (c == 'F') {
        cin >> arrPhanSo1 >> arrPhanSo2;
        Array<PhanSo> sum = arrPhanSo1 + arrPhanSo2; 

        cout << arrPhanSo1 << endl;
        cout << "MAX 1 = " << arrPhanSo1.phanTuMax() << endl;
        cout << "SUM 1 = " << arrPhanSo1.tongPhanTu() << endl;
        Array<PhanSo> res1 = sapXep(arrPhanSo1); cout << res1 << endl;

        cout << arrPhanSo2 << endl;
        cout << "MAX 2 = " << arrPhanSo2.phanTuMax() << endl;
        cout << "SUM 2 = " << arrPhanSo2.tongPhanTu() << endl;
        Array<PhanSo> res2 = sapXep(arrPhanSo2, '>'); cout << res2 << endl;

        cout << sum;
    }

    return 0;
}