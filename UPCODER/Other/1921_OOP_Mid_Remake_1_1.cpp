#include <iostream>
using namespace std;

class Contestant {
private:
    string id;
    int n;
    int *scores;
public:
    Contestant() {
        id = "";
        n = 0;
        scores = new int[15];
    }

    Contestant(string id, int n, int *scores) {
        this->id = id;
        this->n = n;
        this->scores = scores;
    }

    Contestant(const Contestant &other) {
        id = other.id;
        n = other.n;
        scores = other.scores;
    }

    void setN(int n) {
        this->n = n;
    }

    int getAC() {
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (scores[i] > -1) cnt++;
        return cnt;
    }

    int getTime() {
        int res = 0;
        for (int i = 0; i < n; i++) 
            if (scores[i] > -1) res += scores[i];
        return res;
    }

    friend istream &operator >> (istream &in, Contestant &ct) {
        in >> ct.id;
        for (int i = 0; i < ct.n; i++)
            in >> ct.scores[i];
        return in;
    }

    friend ostream &operator << (ostream &out, Contestant ct) {
        out << ct.id << "-" << ct.getAC() << "-" << ct.getTime();
        return out;
    }
};

int main() {
    int c, n;
    cin >> c >> n;

    Contestant arr[c]; 
    for (Contestant &x : arr) {
        x.setN(n);
        cin >> x;
    }

    for (Contestant x : arr)
        cout << x << endl;

    return 0;
}