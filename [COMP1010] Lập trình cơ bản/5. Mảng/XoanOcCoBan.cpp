#include <iostream>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int row, column, cnt = 1;
    cin >> row >> column;
    int arr[row][column];
    int rowTop = 0, rowBottom = row-1;
    int columnLeft = 0, columnRight = column-1;

    while (rowTop <= rowBottom && columnLeft <= columnRight) {
        for (int i = columnLeft; i <= columnRight; i++)   
            arr[rowTop][i] = cnt++;
        rowTop++;

        for (int i = rowTop; i <= rowBottom; i++)
            arr[i][columnRight] = cnt++;
        columnRight--;

        for (int i = columnRight; i >= columnLeft; i--)
            arr[rowBottom][i] = cnt++;
        rowBottom--;

        for (int i = rowBottom; i >= rowTop; i--) 
            arr[i][columnLeft] = cnt++;
        columnLeft++;
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    return 0;
}