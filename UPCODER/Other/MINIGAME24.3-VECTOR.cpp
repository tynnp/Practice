#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, tmp;
    vector<int> v;
    cin >> n;
   
    for (int i = 0; i < n; i++) {
	    cin >> tmp;
	    v.push_back(tmp);
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
	    cin >> tmp;
	    vector<int>::iterator it = lower_bound(v.begin(), v.end(), tmp);

	    if (v[it - v.begin()] == tmp)
		    cout << "Yes " << (it - v.begin() + 1) << endl;
        else
		    cout << "No " << (it - v.begin() + 1) << endl;
    }

    return 0;
}
