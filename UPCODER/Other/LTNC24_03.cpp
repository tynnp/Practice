#include <iostream>
using namespace std;

struct Array {
    int size;
    int values[100];

    int& operator [] (int index) {
        return values[index];
    }

    Array operator - () {
        Array res;
        res.size = size;
        for (int i = 0; i < size; i++)
            res[i] = -values[i];
        return res;
    }
};

istream &operator >> (istream &cin, Array &arr) {
    cin >> arr.size;
    for (int i = 0; i < arr.size; i++)
        cin >> arr[i];
    return cin;
}

ostream &operator << (ostream &cout, Array arr) {
    for (int i = 0; i < arr.size; i++)
        cout << arr[i] << " ";
    return cout;
}

Array operator + (Array a, Array b) {
    Array res;
    res.size = max(a.size, b.size);

    for (int i = 0; i < res.size; i++) {
        if (i < a.size && i < b.size) res[i] = a[i] + b[i];
        else if (i < a.size) res[i] = a[i];
        else res[i] = b[i];
    }

    return res;
}

int main() {
    Array a, b;
    cin >> a >> b;
    cout << a + b << endl;
    cout << -a << endl;
    cout << -b << endl;
    cout << -a + -b << endl;
    return 0;
}