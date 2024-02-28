#include <iostream>
#include <cmath>
using namespace std;

struct KG2C {
    int x, y;

    friend istream& operator >> (istream &in, KG2C &toaDo) {
        in >> toaDo.x >> toaDo.y;
        return in;
    }

    friend ostream& operator << (ostream &out, KG2C toaDo) {
        out << "(" << toaDo.x << ", " << toaDo.y << ")";
        return out;
    }

    double operator - (KG2C other) {
        return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2));
    }

    bool operator < (KG2C other) {
        if (x < other.x) return true;
        if (x == other.x && y < other.y) return true;
        return false;
    }
};

struct KG3C {
    int x, y, z;

    friend istream& operator >> (istream &in, KG3C &toaDo) {
        in >> toaDo.x >> toaDo.y >> toaDo.z;
        return in;
    }

    friend ostream& operator << (ostream &out, KG3C toaDo) {
        out << "(" << toaDo.x << ", " << toaDo.y << ", " << toaDo.z << ")";
        return out;
    }

    double operator - (KG3C other) {
        return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2) + pow(other.z - z, 2));
    }

    bool operator < (KG3C other) {
        if (x < other.x) return true;
        if (x == other.x && y < other.y) return true;
        if (x == other.x && y == other.y && z < other.z) return true;
        return false;
    }
};

template <typename T>
struct Array {
    int size = 0;
    T values[100];

    friend istream& operator >> (istream &in, Array &array) {
        T n; 
        in >> n;
        array.values[array.size++] = n;
        return in;
    } 

    friend ostream& operator << (ostream &out, Array array) {
        for (int i = 0; i < array.size; i++) 
            out << array.values[i] << " ";
        return out;
    }

    double khoangCachLonNhat() {
        double res = 0;
        for (int i = 0; i < size; i++)
            for (int j = i + 1; j < size; j++)
                if (res < values[i] - values[j])
                    res = values[i] - values[j];
        return res;
    }

    void sapXepTangDan() {
        for (int i = 1; i < size; i++) {
            int j = i;
            while (j > 0 && values[j] < values[j-1]) {
                swap(values[j], values[j-1]);
                j--;
            }
        }
        return;
    }

    void sapXepGiamDan() {
        for (int i = 1; i < size; i++) {
            int j = i;
            while (j > 0 && values[j-1] < values[j]) {
                swap(values[j-1], values[j]);
                j--;
            }
        }
        return;
    }
};

int main() {
    string str; 
    Array<KG2C> arr2C;
    Array<KG3C> arr3C;

    while (cin >> str) {
        if (str == "Oxy") cin >> arr2C;
        else if (str == "Oxyz") cin >> arr3C;
    }

    arr2C.sapXepTangDan(); cout << arr2C << endl;
    arr3C.sapXepGiamDan(); cout << arr3C << endl;

    cout << roundf(arr2C.khoangCachLonNhat()*1000)/1000 << endl;
    cout << roundf(arr3C.khoangCachLonNhat()*1000)/1000 << endl;

    return 0;
}