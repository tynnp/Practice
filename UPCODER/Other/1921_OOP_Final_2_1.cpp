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
};

//------------------------------------------------------------------------------------------------------------------------------------

int main() {
    int number; cin >> number;
    while (number--) {
        Person p; cin >> p; cout << p;
    }
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

//------------------------------------------------------------------------------------------------------------------------------------