#include <iostream>
#include <iomanip>
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

    bool operator > (StringClass other) {
        return getStringLength() > other.getStringLength();
    }

    bool operator < (StringClass other) {
        return getStringLength() < other.getStringLength();
    }
};

class StringClass2 : public StringClass {
public:
    StringClass2() {}
    StringClass2(string data) : StringClass(data) {}

    StringClass2(const StringClass2 &other) {
        data = other.data;
    }

    ~StringClass2() {}

    string getStringInverse() {
        string str = "";
        for (int i = getStringLength()-1; i >= 0; i--) 
            str += data[i];
        return str;
    }

    int operator + (StringClass2 other) {
        return getStringLength() + other.getStringLength();
    }

    int operator - (StringClass2 other) {
        return getStringLength() - other.getStringLength();
    }
};

int main() {
    StringClass2 a, b;
    char c;
    cin >> a >> b >> c;
    
    cout << a.getStringInverse() << endl;
    cout << b.getStringInverse() << endl;

    if (a > b) cout << "LONHON" << endl;
    else if (a < b) cout << "BEHON" << endl;
    else cout << "BANG" << endl;

    if (c == '+') cout << abs(a + b);
    else cout << abs(a - b);

    return 0;
}