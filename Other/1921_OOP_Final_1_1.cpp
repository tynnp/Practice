#include <iostream>
#include <vector>
using namespace std;

class Device {
private: 
    string model;
    string manufactory;
    int power;
    double cost;
public:
    Device();
    Device(string, string, int, double);
    double totalCost();
    friend istream& operator >> (istream&, Device&);
    friend ostream& operator << (ostream&, Device);
};

void runMainDevice(int n);

//-------------------------------------------------------------------

int main() {
    int n; cin >> n;
    runMainDevice(n);
    return 0;
}

//-------------------------------------------------------------------

Device::Device() {
    model = "";
    manufactory = "";
    power = 0;
    cost = 0;
}

double Device::totalCost() {
    return cost + cost * 0.1;
}

istream& operator >> (istream& in, Device& dev) {
    in >> dev.model >> dev.manufactory;
    in >> dev.power >> dev.cost;
}

ostream& operator << (ostream& out, Device dev) {
    out << dev.model << "-" << dev.manufactory << "-";
    out << dev.power << "W-" << dev.totalCost() << endl;
}

//-------------------------------------------------------------------

void runMainDevice(int n) {
    vector<Device> vt(n);
    for (Device& dev : vt) cin >> dev;
    for (Device dev : vt) cout << dev;
}