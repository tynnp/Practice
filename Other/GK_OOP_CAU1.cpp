#include <iostream>
using namespace std;

class StringClass {
protected:
    string data;
public:
    StringClass() {}
    StringClass(string data): data(data) {}

    StringClass(const StringClass &other) {
        data = other.data;
    }

    ~StringClass() {}

    void setData(string data) {
        this->data = data;
        return;
    }

    string getData() {
        return data;
    }

    int getStringLength() {
        return data.length();
    }

    string stringUpperCase() {
        string str = "";
        for (char c : data) 
            str += toupper(c);
        return str;
    }

    friend istream &operator >> (istream &in, StringClass &sc) {
        getline(in, sc.data);
        return in;
    }

    friend ostream &operator << (ostream &out, StringClass sc) {
        out << sc.data;
        return out;
    }

    bool operator < (StringClass other) {
        return getStringLength() < other.getStringLength();
    }
};

int main() {
    StringClass a, b;
    cin >> a >> b;
    cout << a << endl << b << endl;
    if (a < b) cout << "NO\n" << b.stringUpperCase();
    else cout << "YES\n" << a.stringUpperCase();
    return 0;
}