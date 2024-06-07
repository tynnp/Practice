#include <bits/stdc++.h>
using namespace std;

const int SIZE = 9;
int banCo[SIZE][SIZE];

void print() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            cout << banCo[i][j] << " ";
        cout << '\n';
    }
}

bool check(int hang, int cot, int num) {
    for (int i = 0; i < SIZE; i++)
        if (banCo[hang][i] == num || banCo[i][cot] == num)
            return false;
    
    int hangNho = hang - hang % 3;
    int cotNho = cot - cot % 3;
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (banCo[hangNho + i][cotNho + j] == num)
                return false;
    
    return true;
}

bool checkViTri(int &hang, int &cot) {
    for (hang = 0; hang < SIZE; hang++)
        for (cot = 0; cot < SIZE; cot++)
            if (banCo[hang][cot] == 0)
                return true;
    return false;
}

bool giaiSudoku() {
    int hang, cot;
    
    if (!checkViTri(hang, cot))
        return true;
        
    for (int i = 1; i <= SIZE; i++) {
        if (check(hang, cot, i)) {
            banCo[hang][cot] = i;
            if (giaiSudoku()) return true;
            banCo[hang][cot] = 0;
        }
    }
    
    return false;
}

int main() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            cin >> banCo[i][j];
    
    if (giaiSudoku()) print();
    else cout << -1;
    return 0;
}