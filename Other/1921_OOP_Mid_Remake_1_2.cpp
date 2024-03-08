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

    string getID() {
        return id;
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

    bool operator < (Contestant other) {
        if (getAC() < other.getAC()) return true;
        if (getAC() == other.getAC() && getTime() > other.getTime()) return true;
        return false;
    }

    bool operator > (Contestant other) {
        if (getAC() > other.getAC()) return true;
        if (getAC() == other.getAC() && getTime() < other.getTime()) return true;
        return false;
    }

    bool operator == (Contestant other) {
        return getAC() == other.getAC() && getTime() == other.getTime();
    }

    int check(Contestant other) {
        if (*this > other) return 0;
        int x = getAC(), y = other.getAC();
        if (*this == other && x+1 <= n) return 1;
        if (*this < other && getTime() < other.getTime() && x+1 <= n) return 1;
        if (*this < other && y+1 <= n) return y+1-x;
        return -1;
    }
};

int main() {
    int c, n;
    string s, t;
    cin >> c >> n;

    Contestant arr[c]; 
    Contestant ctS, ctT;

    for (Contestant &x : arr) {
        x.setN(n);
        cin >> x;
    }

    cin >> s >> t;
    
    for (Contestant x : arr) {
        if (x.getID() == s) ctS = x;
        if (x.getID() == t) ctT = x;
    }

    if (ctS < ctT) cout << '<';
    else if (ctS > ctT) cout << '>';
    else cout << '=';
    cout << endl;

    cout << ctS.check(ctT);
    return 0;
}