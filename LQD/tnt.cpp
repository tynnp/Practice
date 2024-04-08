#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 9 * 9; // Tổng lớn nhất của các chữ số (9*9=81)
bool isPrime[MAX + 1];
int dp[10][2][MAX + 1];

vector<int> numToVec(int N) {
    vector<int> digits;
    while(N > 0) {
        digits.push_back(N % 10);
        N /= 10;
    }
    reverse(digits.begin(), digits.end());
    return digits;
}

void sieve() {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for (int p = 2; p * p <= MAX; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= MAX; i += p)
                isPrime[i] = false;
        }
    }
}

// dp[pos][tight][sum]: số lượng số tại vị trí pos, với giới hạn tight và tổng các chữ số là sum
int countPrimeSum(const vector<int>& digits, int pos, int tight, int sum) {
    if (pos == digits.size()) return isPrime[sum];
    int &ans = dp[pos][tight][sum];
    if (ans != -1) return ans;

    ans = 0;
    int limit = tight ? digits[pos] : 9;

    for (int nextDigit = 0; nextDigit <= limit; ++nextDigit) {
        ans += countPrimeSum(digits, pos + 1, tight && (nextDigit == digits[pos]), sum + nextDigit);
    }

    return ans;
}

int solve(int N) {
    vector<int> digits = numToVec(N);
    memset(dp, -1, sizeof(dp));
    return countPrimeSum(digits, 0, 1, 0);
}

int main() {
    sieve(); 
    int A, B;
    cin >> A >> B;

    int result = solve(B) - solve(A - 1);
    cout << result << endl;

    return 0;
}
