#include <iostream>
using namespace std;

struct MangMotChieu {
    int size;
    int *values;

    MangMotChieu& operator = (MangMotChieu& other) {
        this->size = other.size;
        for (int i = 0; i < other.size; i++)
            this->values[i] = other[i];
        return *this;
    }

    MangMotChieu operator + (MangMotChieu arr) {
        MangMotChieu res;
        res.size = max(this->size, arr.size);
        res.values = new int[res.size];
        for (int i = 0; i < res.size; i++)
            res.values[i] = this->values[i] + arr.values[i];
        return res;
    }

    bool operator == (MangMotChieu other) {
        if (this->size != other.size) return false;
        for (int i = 0; i < other.size; i++)
            if (this->values[i] != other.values[i])
                return false;
        return true;
    }

    bool operator != (MangMotChieu other) {
        if (this->size == other.size) return false;
        for (int i = 0; i < other.size; i++)
            if (this->values[i] == other.values[i])
                return false;
        return true;
    }

    int operator [] (int index) {
        if (index > 0 && index < this->size) 
            return this->values[index];
    }
};

ostream& operator << (ostream& out, MangMotChieu arr) {
    for (int i = 0; i < arr.size; i++)
        out << arr.values[i] << " ";
    return out;
}

istream& operator >> (istream& in, MangMotChieu& arr) {
    in >> arr.size;
        arr.values = new int[arr.size];
        for (int i = 0; i < arr.size; i++)
        in >> arr.values[i];
    return in;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    MangMotChieu arr1, arr2;
    cin >> arr1 >> arr2;
    if (arr1 == arr2) cout << "yes";
    else cout << "no";
    return 0;
}