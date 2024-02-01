#include <iostream>
using namespace std;

struct MangMotChieu {
    int size;
    int *value;

    MangMotChieu& operator = (MangMotChieu& other) {
        this->size = other.size;
        for (int i = 0; i < other.size; i++)
            this->value[i] = other[i];
        return* this;
    }

    MangMotChieu operator + (MangMotChieu arr) {
        MangMotChieu res;
        res.size = max(this->size, arr.size);
        res.value = new int[res.size];
        for (int i = 0; i < res.size; i++)
            res.value[i] = this->value[i] + arr.value[i];
        return res;
    }

    bool operator == (MangMotChieu other) {
        if (this->size != other.size) return false;
        for (int i = 0; i < other.size; i++)
            if (this->value[i] != other.value[i])
                return false;
        return true;
    }

    bool operator != (MangMotChieu other) {
        if (this->size == other.size) return false;
        for (int i = 0; i < other.size; i++)
            if (this->value[i] == other.value[i])
                return false;
        return true;
    }

    int operator [] (int index) {
        if (index > 0 && index < this->size) 
            return this->value[index];
    }
};

ostream& operator << (ostream& out, MangMotChieu arr) {
    for (int i = 0; i < arr.size; i++)
        out << arr.value[i] << " ";
    return out;
}

istream& operator >> (istream& in, MangMotChieu& arr) {
    in >> arr.size;
        arr.value = new int[arr.size];
        for (int i = 0; i < arr.size; i++)
        in >> arr.value[i];
    return in;
}

int main() {
    MangMotChieu arr1, arr2;
    cin >> arr1 >> arr2;
    MangMotChieu res = arr1 + arr2;
    cout << res;
    return 0;
}