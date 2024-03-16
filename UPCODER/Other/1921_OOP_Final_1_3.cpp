#include <iostream>
#include <vector>
using namespace std;

//? class Device-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Device {
protected: 
    string model;
    string manufactory;
    int power;
    double cost;
public:
    Device(); Device(string, string, int, double);
    string getModel(); string getManufactory();
    int getPower(); double getCost(); double totalCost();
    friend istream& operator >> (istream&, Device&);
    friend istream& operator >> (istream&, pair<int, Device>&);
    friend ostream& operator << (ostream&, Device);
};

//? class Television-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Television : public Device {
private:
    int size;
    int width;
    int height;
public: 
    Television(); Television(string, string, int, double);
    friend istream& operator >> (istream&, Television&);
    friend ostream& operator << (ostream&, Television);
};

//? class Refrigerator-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

 class Refrigerator : public Device {
private:
    int capacity;
    double weight;
public: 
    Refrigerator(); Refrigerator(string, string, int, double);
    friend istream& operator >> (istream&, Refrigerator&);
    friend ostream& operator << (ostream&, Refrigerator);
 };

//? function-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void runMainDevice();
void tongSoTien(vector<pair<int, Device>>, string, string);
void soSanhDevice(vector<pair<int, Device>>, string, string);
void televisionReNhat(vector<Television>);
void refrigeratorDatNhat(vector<Refrigerator>);
bool operator < (Device, Device);
bool operator > (Device, Device);
bool operator == (Device, Device);
double operator * (Device, int);

//! Main----------------------------------------------------------------------------------------------------------------------------------------------------------------------

int main() {
    runMainDevice();
    return 0;
}
//! ----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//? class Device-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

Device::Device() {
    model = "";
    manufactory = "";
    power = 0;
    cost = 0;
}

Device::Device(string model, string manufactory, int power, double cost) {
    this->model = model;
    this->manufactory = manufactory;
    this->power = power;
    this->cost = cost;
}

double Device::totalCost() {
    return cost + cost * 0.1;
}

istream& operator >> (istream& in, Device& dev) {
    in >> dev.model >> dev.manufactory;
    in >> dev.power >> dev.cost;
    return in;
}

ostream& operator << (ostream& out, Device dev) {
    out << dev.model << "-" << dev.manufactory << "-";
    out << dev.power << "W-" << dev.totalCost() <<"USD-";
    return out;
}

istream& operator >> (istream& in, pair<int, Device>& p) {
    in >> p.second >> p.first;
    return in;
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

//? class Television-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

Television::Television() {
    size = 0;
    width = 0;
    height = 0;
}

Television::Television(string model, string manufactory, int power, double cost) :
Device(model, manufactory, power, cost) {}

istream& operator >> (istream& in, Television& tl) {
    in >> tl.model >> tl.manufactory >> tl.power >> tl.cost;
    in >> tl.size >> tl.width >> tl.height;
    return in;
}

ostream& operator << (ostream& out, Television tl) {
    Device dev(tl.model, tl.manufactory, tl.power, tl.cost);
    out << dev << tl.size << "Inch-" << tl.width << "x" << tl.height << endl; 
    return out;
}

//? class Refrigerator-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Refrigerator::Refrigerator() {
    capacity = 0;
    weight = 0;
}

Refrigerator::Refrigerator(string model, string manufactory, int power, double cost) :
Device(model, manufactory, power, cost) {}

istream& operator >> (istream& in, Refrigerator& rg) {
    in >> rg.model >> rg.manufactory >> rg.power >> rg.cost;
    in >> rg.capacity >> rg.weight;
    return in;
}

ostream& operator << (ostream& out, Refrigerator rg) {
    Device dev(rg.model, rg.manufactory, rg.power, rg.cost);
    out << dev << rg.capacity << "Lit-" << rg.weight << "Kg\n";
    return out;
}

//? function-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void runMainDevice() {
    int n; cin >> n;
    vector<Television> tl;
    vector<Refrigerator> rg;
    while (n--) {
        int m; cin >> m;
        if (m == 0) {
            Television a; cin >> a;
            tl.push_back(a); cout << a;
        } else {
            Refrigerator b; cin >> b;
            rg.push_back(b); cout << b;
        }
    } 
    televisionReNhat(tl);
    refrigeratorDatNhat(rg);
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

void televisionReNhat(vector<Television> vt) {
    if (vt.size()) {
        vector<string> res;
        double min = vt[0].totalCost();
        for (int i = 1; i < vt.size(); i++)
            if (min > vt[i].totalCost()) min = vt[i].totalCost();
        for (auto x : vt) if (x.totalCost() == min)
            res.push_back(x.getModel());
        for (string x : res) cout << x << " ";
    } else cout << "-1\n";
}

void refrigeratorDatNhat(vector<Refrigerator> vt) {
    if (vt.size()) {
        vector<string> res;
        double max = vt[0].totalCost();
        for (int i = 1; i < vt.size(); i++)
            if (max < vt[i].totalCost()) max = vt[i].totalCost();
        for (auto x : vt) if (x.totalCost() == max)
            res.push_back(x.getModel());
        for (string x : res) cout << x << " ";
    } else cout << "-1\n";
}