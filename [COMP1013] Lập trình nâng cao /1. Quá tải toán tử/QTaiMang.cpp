#include <iostream>
using namespace std;

struct MangMotChieu {
    int size;
    int values[100];

    int& operator [] (int index);
    void operator = (MangMotChieu &arr);
};

istream& operator >> (istream &in, MangMotChieu &arr);
ostream& operator << (ostream &out, MangMotChieu arr);
MangMotChieu operator + (MangMotChieu arr1, MangMotChieu arr2);
bool operator == (MangMotChieu arr1, MangMotChieu arr2);
bool operator != (MangMotChieu arr1, MangMotChieu arr2);

int main() {
    MangMotChieu arr1, arr2;
    cin >> arr1 >> arr2;
    if (arr1 == arr2) cout << "yes";
    else cout << "no";
    return 0;
}

istream& operator >> (istream &in, MangMotChieu &arr) {
    in >> arr.size;
    for (int i = 0; i < arr.size; ++i) 
        in >> arr.values[i];
    return in;
}

ostream& operator << (ostream &out, MangMotChieu arr) {
    for (int i = 0; i < arr.size; ++i) 
        out << arr.values[i] << " ";
    return out;
}

void MangMotChieu::operator = (MangMotChieu &arr) {
    size = arr.size;
    for (int i = 0; i < arr.size; ++i) 
        values[i] = arr.values[i];
    return;
}

int& MangMotChieu::operator [] (int index) {
    return values[index];
}

MangMotChieu operator + (MangMotChieu arr1, MangMotChieu arr2) {
    MangMotChieu result;
    result.size = arr1.size + arr2.size;

    for (int i = 0; i < arr1.size; ++i) 
        result.values[i] = arr1.values[i];
    
    for (int i = arr1.size, j = 0; i < result.size; ++i, ++j) 
        result.values[i] = arr2.values[j];
    
    return result;
}

bool operator == (MangMotChieu arr1, MangMotChieu arr2) {
    if (arr1.size != arr2.size) return false;
    
    for (int i = 0; i < arr1.size; ++i) 
        if (arr1.values[i] != arr2.values[i]) 
            return false;
        
    return true;
}

bool operator != (MangMotChieu arr1, MangMotChieu arr2) {
    return !(arr1 == arr2);
}
