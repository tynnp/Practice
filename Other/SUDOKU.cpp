#include <iostream>
using namespace std;

const int SIZE = 9;

void inSudoku(int arr[SIZE][SIZE]) {
    for (int hang = 0; hang < SIZE; hang++) {
        for (int cot = 0; cot < SIZE; cot++)
            cout << arr[hang][cot] << " ";
        cout << '\n';
    }
}

bool check(int arr[SIZE][SIZE], int hang, int cot, int num) {
    for (int x = 0; x < SIZE; x++)
        if (arr[hang][x] == num || arr[x][cot] == num)
            return false;

    int hangBatDau = hang - hang % 3, cotBatDau = cot - cot % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (arr[i + hangBatDau][j + cotBatDau] == num)
                return false;

    return true;
}

bool timViTri(int arr[SIZE][SIZE], int &hang, int &cot) {
    for (hang = 0; hang < SIZE; hang++)
        for (cot = 0; cot < SIZE; cot++)
            if (arr[hang][cot] == 0)
                return true;
    return false; 
}

bool giaiSudoku(int arr[SIZE][SIZE]) {
    int hang, cot;

    if (!timViTri(arr, hang, cot))
        return true;

    for (int num = 1; num <= SIZE; num++) {
        if (check(arr, hang, cot, num)) {
            arr[hang][cot] = num;
            if (giaiSudoku(arr))
                return true;
            arr[hang][cot] = 0;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            cin >> arr[i][j];

    if (giaiSudoku(arr)) inSudoku(arr);
    else cout << "-1";

    return 0;
}
