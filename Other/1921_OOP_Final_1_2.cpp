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
    Device(); double totalCost();
    Device(string, string, int, double);
    string getModel(); string getManufactory();
    int getPower(); double getCost();
    friend istream& operator >> (istream&, Device&);
    friend istream& operator >> (istream&, pair<int, Device>&);
    friend ostream& operator << (ostream&, Device);
};

void runMainDevice();
void tongSoTien(vector<pair<int, Device>>, string, string);
void soSanhDevice(vector<pair<int, Device>>, string, string);
bool operator < (Device, Device);
bool operator > (Device, Device);
bool operator == (Device, Device);
double operator * (Device, int);

//-------------------------------------------------------------------

int main() {
    runMainDevice();
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

istream& operator >> (istream& in, pair<int, Device>& p) {
    in >> p.second >> p.first;
}

//-------------------------------------------------------------------

void runMainDevice() {
    int n; cin >> n;
    vector<pair<int, Device>> vt(n);
    for (pair<int, Device>& p : vt) cin >> p;
    string s, t; cin >> s >> t;
    tongSoTien(vt, s, t);
    soSanhDevice(vt, s, t);
}

string Device::getModel() {
    return model;
}

string Device::getManufactory() {
    return manufactory;
}

int Device::getPower() {
    return power;
}

double Device::getCost() {
    return cost;
}

bool operator > (Device d1, Device d2) {
    if (d1.getPower() > d2.getPower()) return true;
    else if (d1.getPower() == d2.getPower()) {
        if (d1.getCost() < d2.getCost()) return true;
    } return false;
}

bool operator < (Device d1, Device d2) {
    if (d1.getPower() < d2.getPower()) return true;
    else if (d1.getPower() == d2.getPower()) {
        if (d1.getCost() > d2.getCost()) return true;
    } return false;
}

bool operator == (Device d1, Device d2) {
    return (d1.getPower() == d2.getPower() && d1.getCost() == d2.getCost()); 
}

double operator * (Device dev, int n) {
    return dev.totalCost() * n;
}

void tongSoTien(vector<pair<int, Device>> vt, string s, string t) {
    double result = 0;
    for (pair<int, Device> p : vt) 
        result += p.second * p.first;
    cout << result << endl;

}

void soSanhDevice(vector<pair<int, Device>> vt, string s, string t) {
    Device d1, d2;
    for (pair<int, Device> p : vt) {
        if (p.second.getModel() == s) d1 = p.second;
        if (p.second.getModel() == t) d2 = p.second;
    }
    if (d1 > d2) cout << '>';
    else if (d1 < d2) cout << '<';
    else cout << '=';
    
}