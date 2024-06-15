#include <bits/stdc++.h>
using namespace std;

struct Set {
    int size;
    int *element;
    
    Set(int size) {
        this->size = 0;
        element = new int[size];
    }
    
    ~Set() {
        delete[] element;
    }
    
    bool checkOf(int n) {
        for (int i = 0; i < size; i++)
            if (element[i] == n)
                return true;
        return false;
    }
    
    void sort() {
        for (int i = 1; i < size; i++) {
            int j = i;
            while (j > 0 && element[j-1] > element[j]) {
                swap(element[j-1], element[j]);
                j--;
            }
        }
    }
    
    void print() {
        for (int i = 0; i < size; i++)
            cout << element[i] << " ";
    }
    
    bool insert(int n) {
        if (!checkOf(n)) {
            element[size++] = n;
            this->sort();
            return true;
        } else return false;
    }
}; 

int main() {
    int tmp, n;
    cin >> n;
    Set mySet(n);
    
    while (cin >> tmp) 
        mySet.insert(tmp);
    mySet.print();
    return 0;
}