#include <iostream>
using namespace std;

class Array {
private:
    int size;
    int values[100];
public:
    friend istream &operator >> (istream &in, Array &arr) {
        arr.size = 0;
        while(in >> arr.values[arr.size])
            arr.size++;
        return in;
    }

    friend ostream &operator << (ostream &out, Array arr) {
        for (int i = 0; i < arr.size; i++)
            out << arr.values[i] << " ";
        return out;
    }

    int getSize() {
        return size;
    }

    int& operator [] (int index) {
        return values[index];
    }

    void sapXepTang() {
        for (int i = 1; i < size; i++) {
            int j = i;
            while (j > 0 && values[j-1] > values[j])
                swap(values[j-1], values[j]), j--;
        }
        return;
    }

    void sapXepGiam() {
        for (int i = 1; i < size; i++) {
            int j = i;
            while (j > 0 && values[j-1] < values[j])
                swap(values[j-1], values[j]), j--;
        }
        return;
    }

    bool findOf(int x) {
        for (int i = 0; i < size; i++)
            if (values[i] == x) return true;
        return false; 
    }
};

int main() {
    int x;
    Array arr, tmp;
    cin >> x >> arr;
    tmp = arr;

    cout << arr.getSize() << endl;
    cout << (arr.findOf(x) ? "TRUE\n" : "FALSE\n");

    arr.sapXepTang(); 
    cout << arr << endl;

    tmp[0] = tmp[0] + 1;
    tmp.sapXepGiam(); 
    cout << tmp << endl;
    
    return 0;
}