#include <iostream>
#include <string>
using namespace std;

string tmp, res = "";
int n, arr[100][100];
int dx[] = {0, 1};
int dy[] = {1, 0};

int binaryToDecimal(string binary) {
    int decimal = 0;
    int base = 1;
    int len = binary.length();
    for (int i = len - 1; i >= 0; i--) {
        if (binary[i] == '1')
            decimal += base;
        base *= 2;
    }
    return decimal;
}

bool check(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < n && arr[i][j] != -1;
}

void Try(int i, int j) {
    if (i == n-1 && j == n-1) {
        res = (res < tmp && res != "" ? res : tmp);
        return;
    }

    for (int x = 0; x < 2; x++) {
        int u = i + dx[x];
        int v = j + dy[x];
        if (check(u, v)) {
            tmp += arr[u][v] + '0';
            Try(u, v);
            tmp.pop_back(); 
        }
    }
}

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
            
    tmp += (arr[0][0] + '0');
    Try(0, 0);
    cout << binaryToDecimal(res);
    return 0;
}
