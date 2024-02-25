#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

struct Diem {
    int x, y, z;

    friend istream &operator >> (istream &in, Diem &diem) {
        in >> diem.x >> diem.y >> diem.z;
        return in;
    }

    friend ostream &operator << (ostream &out, Diem diem) {
        out << "(" << diem.x << "," << diem.y << "," << diem.z << ")";
        return out;
    }

    Diem operator + (Diem other) {
        Diem res;
        res.x = x + other.x;
        res.y = y + other.y;
        res.z = z + other.z;
        return res;
    }

    double operator - (Diem other) {
        return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2) + pow(other.z - z, 2));
    }

    bool operator < (Diem other) {
        if (x != other.x) return x < other.x;
        if (y != other.y) return y < other.y;
        return z < other.z;
    }

    bool operator == (Diem other) {
        return (x == other.x || x == other.y || x == other.z) || 
            (y == other.x || y == other.y || y == other.z) || 
            (z == other.x || z == other.y || z == other.z);
    }
};

struct Array {
    int size;
    Diem values[100];

    friend istream &operator >> (istream &in, Array &arr) {
        in >> arr.size;
        for (int i = 0; i < arr.size; i++) 
            in >> arr.values[i];
        return in;
    } 

    friend ostream &operator << (ostream &out, Array arr) {
        for (int i = 0; i < arr.size; i++)
            out << arr.values[i] << " ";
        return out;
    }

    Array operator + (Array other) {
        Array res, arrMax;
        arrMax = (size > other.size ? *this : other);
        int minLen = min(size, other.size);
        int maxLen = max(size, other.size);
        res.size = maxLen;

        for (int i = 0; i < minLen; i++)
            res.values[i] = values[i] + other.values[i];

        for (int i = minLen; i < maxLen; i++)
            res.values[i] = arrMax.values[i];

        return res;
    }

    double* operator - (Array other) {
        double* res = new double[max(size, other.size)];
        int minLen = min(size, other.size);
        int maxLen = max(size, other.size);

        for (int i = 0; i < minLen; i++)
            res[i] = values[i] - other.values[i];

        for (int i = minLen; i < maxLen; i++)
            res[i] = 0;

        return res;
    }

    bool operator == (Array other) {
        if (size != other.size) return false;
        for (int i = 0; i < size; i++)
            if (!(values[i] == other.values[i])) return false;
        return true;
    }

    double khoangCachLonNhat() {
        double res = 0;
        for (int i = 0; i < size; i++)
            for (int j = i+1; j < size; j++)
                if (res < values[i] - values[j])
                    res = values[i] - values[j];
        return res;
    }

    void sapXepTangDan() {
        for (int i = 1; i < size; i++) {
            int j = i;
            while (j > 0 && values[j] < values[j-1])
                swap(values[j-1], values[j]), j--;
        }
        return;
    }

    void sapXepGiamDan() {
        for (int i = 1; i < size; i++) {
            int j = i;
            while (j > 0 && values[j-1] < values[j])
                swap(values[j-1], values[j]), j--;
        }
        return;
    }
};

int main() {
    // ifstream ifile;
    // ofstream ofile;
    // ifile.open("OPERATOR.inp");
    // ofile.open("OPERATOR.out");

    Array list1, list2, list3;
    cin >> list1 >> list2;
    list3 = list1 + list2;
    double* list4 = list1 - list2;
    bool check = (list1 == list2);

    list1.sapXepTangDan();
    cout << list1 << endl;
    cout << roundf(list1.khoangCachLonNhat()*1000)/1000 << endl;

    list2.sapXepGiamDan();
    cout << list2 << endl;
    cout << roundf(list2.khoangCachLonNhat()*1000)/1000 << endl;

    cout << list3 << endl;

    for (int i = 0; i < max(list1.size, list2.size); i++)
        cout << roundf(list4[i]*1000)/1000 << " ";
    cout << endl;

    cout << (check ? "TRUE" : "FALSE");

    // ifile.close();
    // ofile.close();
    return 0;
}