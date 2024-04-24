#include <iostream>
#include <iomanip>
using namespace std;

template<typename T>
struct Array {
    int size;
    T values[100];
    
    T& operator [] (int index) {
        return values[index];
    }
    
    friend istream &operator >> (istream &in, Array<T> &arr) {
        in >> arr.size;
        for (int i = 0; i < arr.size; i++)
            in >> arr[i];
        return in;
    }
    
    T tinhTong() {
        T res = 0;
        for (int i = 0; i < size; i++)
            res += values[i];
        return res;
    }
    
    friend ostream &operator << (ostream &out, Array<T> arr) {
        out << fixed << setprecision(1);
        for (int i = 0; i < arr.size; i++)
            out << arr[i] << " ";
        out << endl << arr.tinhTong();
        return out;
    }
};

template<typename T>
void run() {
    Array<T> arr;
    cin >> arr;
    cout << arr;
}

int main() {
    char kt;
    cin >> kt;
    
    switch (kt) {
        case 'A': run<int>(); break;
        case 'B': run<double>(); break;
    }
    
    return 0;
}
