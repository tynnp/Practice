#include <iostream>
using namespace std;

int main() {
    int n, s, e, result = 0;
    cin >> n >> s >> e;

    if (s >= 8 && s <= 24 && n > 0 && e > s && e <= 24) {
        if (s <= 17 && e <= 17) {
            if (e-s > 3) result = (3*n + (e-s-3)*n*0.7)*0.9;
            else result = ((e-s)*n)*0.9;

        } else if (s <= 17 && e <= 24) {
            if (17-s > 3) result = (3*n + (17-s-3)*n*0.7)*0.9;
            else if (17-s <= 3) result = (17-s)*n*0.9;
            result += (e-17)*n*0.7;

        } else if (s > 17 && e > 17) {
            if (e-s > 3) result = 3*n + (e-s-3)*n*0.7;
            else result = (e-s)*n;
        }
        cout << result;

    } else cout << -1;

    return 0;
}