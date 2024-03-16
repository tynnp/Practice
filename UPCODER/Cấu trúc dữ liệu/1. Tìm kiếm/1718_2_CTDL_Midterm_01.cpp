#include <iostream>
using namespace std;

struct Set {
    int size;
    int* values;

    Set(int N) {
        size = 0;
        values = new int[N+5];
    }

    void add(int n) {
        int res = -1;
        for (int i = 0; i < size; i++)
            if (values[i] == n) {
                res = i;
                break;
            }
        
        if (res == -1) {
            values[size++] = n;
            for (int i = 1; i < size; i++) {
                int j = i;
                while (j > 0 && values[j-1] > values[j])
                    swap(values[j-1], values[j]), j--;
            }
        }
        
        return;
    }

    void print() {
        for (int i = 0; i < size; i++)
            cout << values[i] << " ";
        return;
    }
};

int main() {
    int N;
    cin >> N;
    Set setInt(N);
    
    int tmp;
    while(cin >> tmp) 
        setInt.add(tmp);

    setInt.print();
    return 0;
}