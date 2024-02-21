#include <iostream>
#include <iomanip>
#define endl '\n'
using namespace std;

class Resident {
private:    
    string name;
    int age;
    int apartmentNumber;
    string phoneNumber;
    string email;
public:
    Resident() {}
    
    Resident(string name, int age, int apartmentNumber, string phoneNumber, string email) {
        this->name = name;
        this->age = age;
        this->apartmentNumber = apartmentNumber;
        this->phoneNumber = phoneNumber;
        this->email = email;
    }

    virtual ~Resident() {}
    
    void setName(string name) {
        this->name = name;
        return;
    }

    void setAge(int age) {
        this->age = age;
        return;
    }
    
    void setApartmentNumber(int apartmentNumber) {
        this->apartmentNumber =apartmentNumber;
        return;
    }

    void setPhoneNumber(string phoneNumber) {
        this->phoneNumber = phoneNumber;
        return;
    }

    void setEmail(string email) {
        this->email = email;
        return;
    }

    string getName() {
        return this->name;
    }

    int getAge() {
        return this->age;
    }

    int getApartmentNumber() {
        return this->apartmentNumber;
    }

    string getPhoneNumber() {
        return this->phoneNumber;
    }

    string getEmail() {
        return this->email;
    }

    friend istream& operator >> (istream &in, Resident &resident) {
        getline(in, resident.name);
        in >> resident.age >> resident.apartmentNumber;
        in.ignore();
        getline(in, resident.phoneNumber);
        getline(in, resident.email);
        return in;
    }

    friend ostream& operator << (ostream &out, Resident resident) {
        out << "Ten      : " << resident.name << endl;
        out << "Tuoi     : " << resident.age << endl;
        out << "So nha   : " << resident.apartmentNumber << endl;
        out << "SDT      : " << resident.phoneNumber << endl;
        out << "Email    : " << resident.email << endl;
        return out;
    }
};

class Owner : public Resident {
private:
    int purchaseYear;
public:
    Owner() {}

    Owner(string name, int age, int apartmentNumber, string phoneNumber, string email, int purchaseYear) :
        Resident(name, age, apartmentNumber, phoneNumber, email) {
            this->purchaseYear = purchaseYear;
        }

    void setPurchaseYear(int purchaseYear) {
        this->purchaseYear = purchaseYear;
        return;
    }

    int getPurchaseYear() {
        return this->purchaseYear;
    }

    bool operator <= (int year) {
        return this->purchaseYear <= year;
    }

    friend istream& operator >> (istream &in, Owner &owner) {
        Resident &resident = owner;
        in >> resident;
        in >> owner.purchaseYear;
        in.ignore();
        return in;
    }

    friend ostream& operator << (ostream &out, Owner owner) {
        Resident resident = owner;
        out << resident;
        out << "Nam mua  : " << owner.purchaseYear << endl;
        return out;
    }
};

class Renter : public Resident {
private:
    double price;
public: 
    Renter() {}

    Renter(string name, int age, int apartmentNumber, string phoneNumber, string email, double price) :
        Resident(name, age, apartmentNumber, phoneNumber, email) {
            this->price = price;
        }

    void setPrice(double price) {
        this->price = price;
        return;
    }

    double getPrice() {
        return this->price;
    }

    bool operator >= (double money) {
        return this->price >= money;
    }

    friend istream& operator >> (istream &in, Renter &renter) {
        Resident &resident = renter;
        in >> resident;
        in >> renter.price;
        in.ignore();
        return in;
    }

    friend ostream& operator << (ostream &out, Renter renter) {
        Resident resident = renter;
        out << resident;
        out << "Gia thue : " << renter.price << " trieu" << endl;
        return out;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n, requestType;
    int year; double money;

    cin >> m >> n;
    Owner ownerList[m];
    Renter renterList[n];

    cin.ignore();
    for (Owner &x : ownerList) cin >> x;
    for (Renter &x : renterList) cin >> x;

    cin >> requestType;
    cout << fixed << setprecision(2);

    int index = 0;
    if (requestType == 0) {
        cin >> year;
        cout << "Cac can ho da ban den nam " << year << ":\n";

        for (Owner x : ownerList) {
            if (x <= year) {
                cout << "#" << ++index << endl;
                cout << x;
            }
        }

        if (index == 0) cout << "Khong tim thay!";

    } else if (requestType == 1) {
        cin >> money;
        cout << "Cac can ho co gia tu " << money << " trieu:\n";

        for (Renter x : renterList) {
            if (x >= money) {
                cout << "#" << ++index << endl;
                cout << x;
            }
        }

        if (index == 0) cout << "Khong tim thay!";
    }

    return 0;
}