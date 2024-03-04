#include <iostream>
#include <iomanip>
using namespace std;

class Coin {
private:
    string name;
    float price;
    float low;
    float high;
public:
    Coin() {
        name = "NoName";
        price = 0;
        low = 0;
        high = 0;
    }

    void setName(string name) {
        this->name = name;
        return;
    }

    void setPrice(float price) {
        this->price = price;
        return;
    }

    void setLow(float low) {
        this->low = low;
        return;
    }

    void setHigh(float high) {
        this->high = high;
        return;
    }

    string getName() {
        return name;
    }

    float getPrice() {
        return price;
    }

    float getLow() {
        return low;
    }

    float getHigh() {
        return high;
    }

    float maxChange() {
        return high - low;
    }

    void printCoin() {
        cout << fixed << setprecision(2);
        cout << name << "-" << price << "-" << low << "-" << high << "-" << maxChange() << "\n";
        return;
    }

    friend istream &operator >> (istream &in, Coin &coin) {
        in >> coin.name >> coin.price >> coin.low >> coin.high;
        return in;
    }
};

int main() {
    int n;
    cin >> n;

    Coin arr[n];
    for (auto &x : arr) cin >> x;

    for (auto x : arr) x.printCoin();
    return 0;
}