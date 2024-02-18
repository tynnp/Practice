#include <iostream>
#include <iomanip>
#define endl '\n'
using namespace std;

class Employee {
private:
    int id;
    string firstName;
    string lastName;
    double salary;
public: 
    Employee() {}

    Employee(int id, string firstName, string lastName, double salary) {
        this->id = id;
        this->firstName = firstName;
        this->lastName = lastName;
        this->salary = salary;
    }

    int getID() {
        return id;
    }

    string getFirstName() {
        return firstName;
    }

    string getLastName() {
        return lastName;
    }

    string getName() {
        return firstName + " " + lastName;
    }

    double getSalary() {
        return salary;
    }

    void setSalary(double salary) {
        this->salary = salary;
        return;
    }

    double getAnnualSalary() {
        return salary * 12;
    }    

    double raiseSalary(double percent) {
        return salary + salary*percent/100;
    }

    string toString() {
        string salaryString = "$" + to_string(salary);
        auto it = salaryString.find('.');
        salaryString.erase(it+3);
        return "Employee[id=" + to_string(id) + ",name=" + this->getName() + ",salary=" + salaryString + "]";
    }

    friend istream& operator >> (istream &in, Employee &e) {
        in >> e.id >> e.firstName >> e.lastName >> e.salary;
        return in;
    }

    friend ostream& operator << (ostream &out, Employee e) {
        out << e.toString();
        return out;
    }

    Employee& operator ++() {
        salary += salary*0.1;
        return *this;
    }

    Employee operator ++(int) {
        Employee tmp = *this;
        ++(*this);
        return tmp;
    }

    Employee& operator --() {
        salary -= salary*0.1;
        return *this;
    }

    Employee operator --(int) {
        Employee tmp = *this;
        --(*this);
        return tmp;
    }

    Employee& operator + (double x) {
        salary += x;
        return *this;
    }

    Employee& operator - (double x) {
        salary -= x;
        return *this;
    }

    bool operator > (Employee other) {
        return getAnnualSalary() > other.getAnnualSalary();
    }

    bool operator < (Employee other) {
        return getAnnualSalary() < other.getAnnualSalary();
    }

    bool operator == (Employee other) {
        return getAnnualSalary() == other.getAnnualSalary();
    }

    bool operator != (Employee other) {
        return !(getAnnualSalary() == other.getAnnualSalary());
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Employee* emp1 = new Employee();
    Employee* emp2 = new Employee();
    cin >> *emp1 >> *emp2;

    double a, b;
    cin >> a >> b;

    cout << *emp1 << endl;
    cout << *emp2 << endl;

    if (*emp1 == *emp2) cout << "BANG NHAU\n";
    else if (*emp1 > *emp2) cout << "LON HON\n";
    else if (*emp1 < *emp2) cout << "NHO HON\n";

    cout << fixed << setprecision(2);
    cout << "$" << ((*emp1)++ - a).getSalary() << endl;
    cout << "$" << (--(*emp2) + b).getSalary() << endl;

    delete emp1;
    delete emp2;
    return 0;
}