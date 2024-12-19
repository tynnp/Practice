#include <iostream>
using namespace std;

int main() {
    int n, x;
    bool check = false;
    cin >> n >> x;
    
    int a[1001];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
        
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i] + a[j] == x) {
                cout << "(" << a[i] << "," << a[j] << ")\n";
                check = true;
            }
        }
    }
    
    if (!check) 
        cout << "thì ra đến cả số còn không có cặp giống chủ tus";
        
    return 0;
}