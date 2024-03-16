#include <iostream>
using namespace std;

int main() {
    int arr[] = {3, 7, 11, 8, 4, 9, 2};
    pair<int, int> res = {3, 0};

    for (int i = 0; i < 7; i++)
        if (arr[i] > res.first) 
            res = {arr[i], i};

    cout << res.first << " " << res.second;
    return 0;
}