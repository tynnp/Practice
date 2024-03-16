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
        in >> e.id;
        in.ignore();
        getline(in, e.firstName); 
        getline(in, e.lastName);
        in >> e.salary;
        return in;
    }

    friend ostream& operator << (ostream &out, Employee e) {
        out << e.toString();
        return out;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Employee* emp = new Employee();
    cin >> *emp;

    double a;
    cin >> a;
    
    cout << *emp << endl;
    cout << fixed << setprecision(2);
    cout << "$" << (*emp).raiseSalary(a) << endl;
    (*emp).setSalary((*emp).raiseSalary(a));
    cout << "$" << (*emp).getAnnualSalary() << endl;
    
    delete emp;
    return 0;
}