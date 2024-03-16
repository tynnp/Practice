#include <iostream>
using namespace std;

int main() {
	string a; 
	string b;
    cin >> a;

	int l = 0, r = a.length() - 1;
	while (true) {
		if (l > r) break;
		
		if (a[l] < a[r]) {
			b += a[l];
			l++;

		} else if (a[l] > a[r]) {
			b += a[r];
			r--;

		} else {
			int t = 1;
			while (a[l + t] == a[r - t]) {
				if (t >= (l + r) / 2)break;
				t++;
			}

			if (a[l + t] < a[r - t]) {
				b += a[l];
				l++;
                
			} else {
				b += a[r];
				r--;
			}
		}
	}

	cout << b << endl;
	return 0;
}