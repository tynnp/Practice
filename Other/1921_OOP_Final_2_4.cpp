#include <iostream>
#include <string>
#include <vector>
using namespace std;

//------------------------------------------------------------------------------------------------------------------------------------

class Person {
protected:
    int id;
    string name;
    int year;
    string gender;
public: 
    Person(); Person(const Person&); int getYearOld(); int getID();
    Person(int, string name, int year, string gender);
    friend istream& operator >> (istream&, Person&);
    friend ostream& operator << (ostream&, Person);
    bool operator > (Person); bool operator < (Person);
    static void sapXepPerson(vector<Person>, int);
};

//------------------------------------------------------------------------------------------------------------------------------------

class Employer : public Person {
private: 
    int requirement;
    int maxSalary;
public:
    Employer(); Employer(const Employer&);
    int getRequirement(); int getMaxSalary(); 
    static void maxSalaryPerson(vector<Employer>);
    friend istream& operator >> (istream&, Employer&);
    friend ostream& operator << (ostream&, Employer);
};

//------------------------------------------------------------------------------------------------------------------------------------

class Employee : public Person {
private:
    int exp;
    int deal;
public: 
    Employee();  Employee(const Employee&);
    int getExp(); int getDeal();
    static void minDealPerson(vector<Employee>);
    friend istream& operator >> (istream&, Employee&);
    friend ostream& operator << (ostream&, Employee);
};
    
//------------------------------------------------------------------------------------------------------------------------------------

void phuHopNhieuNhat(vector<Employee>, vector<Employer>);

int main() {
    int number; cin >> number;
    vector<Employee> a;
    vector<Employer> b;

    while (number--) {
        int n; cin >> n;
        if (n == 1) {
            Employee x; cin >> x; 
            a.push_back(x); 
        } else {
            Employer y; cin >> y; 
            b.push_back(y); 
        }
    } 

    phuHopNhieuNhat(a, b);
    return 0;
}

//------------------------------------------------------------------------------------------------------------------------------------

Person::Person() {
    id = 0;
    name = "";
    year = 1900;
    gender = "";
}

Person::Person(const Person& a) {
    this->id = a.id;
    this->name = a.name;
    this->year = a.year;
    this->gender = a.gender;
}

Person::Person(int id, string name, int year, string gender) {
    this->id = id; 
    this->name = name; 
    this->year = year; 
    this-> gender = gender;
}

int Person::getID() {
    return id;
}

int Person::getYearOld() {
    return 2020 - year;
}

istream& operator >> (istream& in, Person& p) {
    in >> p.id; in.ignore();
    getline(in, p.name);
    in >> p.year >> p.gender;
    return in;
}

ostream& operator << (ostream& out, Person p) {
    out << p.id << "-" << p.name << "-" << p.getYearOld() << "-" << p.gender << "-";
    return out;
}


bool Person::operator > (Person a) {
    if (this->getYearOld() > a.getYearOld()) return true;
    else if (this->getYearOld() == a.getYearOld()) if (this->id > a.id) return true;
    return false;
}

bool Person::operator < (Person a) {
    if (this->getYearOld() < a.getYearOld()) return true;
    else if (this->getYearOld() == a.getYearOld()) if (this->id < a.id) return true;
    return false;
}

void Person::sapXepPerson(vector<Person> vt, int flag) {
    if (flag == 0) {
        for (int i = 1; i < vt.size(); i++) {
            int j = i;
            while (j > 0 && vt[j-1] > vt[j]) 
                swap(vt[j-1], vt[j]), j--;
        }
        for (Person p : vt) cout << p;
    } else {
        for (int i = 1; i < vt.size(); i++) {
            int j = i;
            while (j > 0 && vt[j-1] < vt[j]) 
                swap(vt[j-1], vt[j]), j--;
        }
        for (Person p : vt) cout << p;
    }
}

//------------------------------------------------------------------------------------------------------------------------------------

Employer::Employer() {
    requirement = 0;
    maxSalary = 0;
}

Employer::Employer(const Employer& a) : Person(a) {
    this->requirement = a.requirement;
    this->maxSalary = a.maxSalary;
}

int Employer::getMaxSalary() {
    return maxSalary;
}

int Employer::getRequirement() {
    return requirement;
}

istream& operator >> (istream& in, Employer& a) {
    in >> a.id; in.ignore(); getline(in, a.name);
    in >> a.year >> a.gender >> a.requirement >> a.maxSalary;
    return in;
}

ostream& operator << (ostream& out, Employer a) {
    Person p(a.id, a.name, a.year, a.gender); out << p;
    out << a.requirement << "Year-" << a.maxSalary << "USD\n";
}

void Employer::maxSalaryPerson(vector<Employer> vt) {
    if (vt.size()) {
        vector<int> result; int max = vt[0].maxSalary;
        for (Employer x : vt) if (x.maxSalary > max) max = x.maxSalary;
        for (Employer x : vt) if (x.maxSalary == max) result.push_back(x.id);
        for (int x : result) cout << x << " "; cout << endl;
    } else cout << "-1\n";
}

//------------------------------------------------------------------------------------------------------------------------------------

Employee::Employee() {
    exp = 0;
    deal = 0;
}

Employee::Employee(const Employee& a) : Person(a) {
    this->exp = a.exp;
    this->deal = a.deal;
}

int Employee::getDeal() {
    return deal;
}

int Employee::getExp() {
    return exp;
}

istream& operator >> (istream& in, Employee& a) {
    in >> a.id; in.ignore(); getline(in, a.name);
    in >> a.year >> a.gender >> a.exp >> a.deal;
    return in;
}

ostream& operator << (ostream& out, Employee a) {
    Person p(a.id, a.name, a.year, a.gender); out << p;
    out << a.exp << "Year-" << a.deal << "USD\n";
}

void Employee::minDealPerson(vector<Employee> vt) {
    if (vt.size()) {
        vector<int> result; int min = vt[0].deal;
        for (Employee x : vt) if (x.deal < min) min = x.deal;
        for (Employee x : vt) if (x.deal == min) result.push_back(x.id);
        for (int x : result) cout << x << " "; cout << endl;
    } else cout << "-1\n";
}

void phuHopNhieuNhat(vector<Employee> a, vector<Employer> b) {
    if (a.size() && b.size()) {
        vector<pair<int, int>> vt;
        for (Employee x : a) {
            int cnt = 0;
            for (Employer y : b) 
                if (x.getExp() >= y.getRequirement() && 
                x.getDeal() <= y.getMaxSalary()) cnt++;
            vt.push_back({x.getID(), cnt});
        }
        int max = 0;
        for (auto x : vt) if (x.second > max) max = x.second;
        if (max) {
            for (auto x : vt) if (x.second == max) cout << x.first << " ";
        } else cout << -1;
    } else cout << -1;
}