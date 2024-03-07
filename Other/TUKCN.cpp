#include <iostream>
using namespace std;
#define M 1000001

int t[M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

	int s = 0, n, a, b;
	cin >> n;

	for (int i = 1; i < M; i++) {
		t[i] = 1;
		t[i] -= i;
	}

	for (int i = 2; i < M; i++)
		for (int j = i; j < M; j += i)
			t[j] += i;

	for (int i = 0; i < n; i++) {
        int a, b;
		cin >> a >> b;
		cout << (t[a] == b ? "Yes\n" : "No\n");
	}

    return 0;
}