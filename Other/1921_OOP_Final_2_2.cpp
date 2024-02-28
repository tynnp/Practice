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
    Person(); int getYearOld();
    Person(int, string name, int year, string gender);
    friend istream& operator >> (istream&, Person&);
    friend ostream& operator << (ostream&, Person);
    bool operator > (Person); bool operator < (Person);
    static void sapXepPerson(vector<Person>, int);
};
    
//------------------------------------------------------------------------------------------------------------------------------------

int main() {
    int number; cin >> number;
    Person p; vector<Person> vt;

    while (number--) {
        cin >> p; 
        vt.push_back(p);
    } 

    int flag; cin >> flag;
    Person::sapXepPerson(vt, flag);

    return 0;
}

//------------------------------------------------------------------------------------------------------------------------------------

Person::Person() {
    id = 0;
    name = "";
    year = 1900;
    gender = "";
}

Person::Person(int id, string name, int year, string gender) {
    this->id = id; this->name = name; 
    this->year = year; this-> gender = gender;
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
    out << p.id << "-" << p.name << "-" << p.getYearOld() << "-" << p.gender << endl;
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