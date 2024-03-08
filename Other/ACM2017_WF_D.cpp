#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Company {
    int price;
    int day;

    Company(int p, int d) : price(p), day(d) {}
};

int main() {
    int m, n;
    cin >> m >> n;

    vector<Company> producers;
    vector<Company> consumers;

    for (int i = 0; i < m; i++) {
        int p, d;
        cin >> p >> d;
        producers.push_back(Company(p, d));
    }

    for (int i = 0; i < n; i++) {
        int q, e;
        cin >> q >> e;
        consumers.push_back(Company(q, e));
    }

    sort(producers.begin(), producers.end(), [](const Company& a, const Company& b) {
        return a.day < b.day;
    });

    sort(consumers.begin(), consumers.end(), [](const Company& a, const Company& b) {
        return a.day < b.day;
    });

    long long maxProfit = 0;
    int producerIdx = 0;

    for (const auto& consumer : consumers) {
        while (producerIdx < m && producers[producerIdx].day <= consumer.day) {
            maxProfit = max(maxProfit, (long long)(consumer.price - producers[producerIdx].price));
            ++producerIdx;
        }
    }

    cout << maxProfit;
    return 0;
}
