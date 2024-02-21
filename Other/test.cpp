#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

/*** Lớp cha Resident - Cư dân ***/
class Resident {
    string name; //Tên chủ hộ (hoặc người thuê căn hộ)
    int age; //Tuổi
    int apartmentNumber; //Mã số căn hộ
    string phoneNumber; //Số điện thoại
    string email; //Email
public:
    Resident(string n="", int a=18, int an=1, string pn="123", string e="");
    ~Resident();
    string getName();
    int    getAge();
    int    getApartmentNumber();
    string getPhoneNumber();
    string getEmail();
    void setName(string);
    void setAge(int);
    void setApartmentNumber(int);
    void setPhoneNumber(string);
    void setEmail(string);
    friend istream& operator >> (istream& in, Resident& r);
    friend ostream& operator << (ostream& out, Resident r);
};


/*** Lớp con Owner - Sở hữu căn hộ: kế thừa từ lớp cha Resident ***/
class Owner : public Resident {
    int purchaseYear; //Năm mua nhà
public:
    Owner(string n="", int a=18, int an=1, string pn="123", string e="", int py=2003) : 
        Resident(n, a, an, pn, e){
            purchaseYear = py;
        }
    ~Owner(){};
    friend istream& operator >> (istream& in, Owner &o);
    friend ostream& operator << (ostream& out, Owner o);
    bool operator <= (int);
};


/*** Lớp con Renter - Thuê căn hộ:  kế thừa từ lớp cha Resident ***/
class Renter : public Resident {
    double price; //Giá thuê căn hộ hàng tháng
public:
    Renter(string n="", int a=18, int an=1, string pn="123", string e="", double p=1.0) : 
        Resident(n, a, an, pn, e){
            price = p;
        }
    ~Renter(){};
    friend istream& operator >> (istream& in, Renter &re);
    friend ostream& operator << (ostream& out, Renter re);
    bool operator >= (double);
};

/** Các biến toàn cục sử dụng trong chương trình **/
////////////////////////////
vector<Owner> owners;     //
vector<Renter> renters;   //
int requestType;          //
////////////////////////////

/** Các hàm bổ trợ **/
void importInfo();
void exportInfo();


//////////////////// START MAIN ////////////////////
int main() {
    // freopen("text1.txt", "r", stdin);
    // freopen("out1.txt", "w", stdout);
    
    importInfo();
    exportInfo();

    return 0;
}
////////////////////  END MAIN  ////////////////////

/***************** Định nghĩa Lớp cha Resident *****************/
Resident::Resident(string n, int a, int an, string pn, string e){
    name = n;
    age = a;
    apartmentNumber = an;
    phoneNumber = pn;
    email = e;
}
Resident::~Resident(){}
// Get functions
string Resident::getName() {return name;}
int    Resident::getAge(){return age;}
int    Resident::getApartmentNumber(){return apartmentNumber;}
string Resident::getPhoneNumber(){return phoneNumber;}
string Resident::getEmail(){return email;}
// Set functions
void Resident::setName(string n){name = n;}
void Resident::setAge(int a){age = a;}
void Resident::setApartmentNumber(int an){apartmentNumber = an;}
void Resident::setPhoneNumber(string pn){phoneNumber = pn;}
void Resident::setEmail(string e){email = e;}
// Operators
istream& operator >> (istream& in, Resident& r){
    in.ignore();
    getline(in,r.name);
    in >> r.age >> r.apartmentNumber >> r.phoneNumber >> r.email;
    return in;
}
ostream& operator << (ostream& out, Resident r){
    out << "Ten      : " << r.name << "\n";
    out << "Tuoi     : " << r.age << "\n";
    out << "So nha   : " << r.apartmentNumber << "\n";
    out << "SDT      : " << r.phoneNumber << "\n";
    out << "Email    : " << r.email << '\n';
    return out;
}

/***************** Định nghĩa Lớp con Owner *****************/
istream& operator >> (istream& in, Owner &o){
    Resident r;
    in >> r;

    o.setName(r.getName());
    o.setAge(r.getAge());
    o.setApartmentNumber(r.getApartmentNumber());
    o.setPhoneNumber(r.getPhoneNumber());
    o.setEmail(r.getEmail());

    in >> o.purchaseYear;
    return in;
}
ostream& operator << (ostream& out, Owner o){
    Resident *r = new Resident(o.getName(), o.getAge(), o.getApartmentNumber(), o.getPhoneNumber(), o.getEmail());
    out << *r;
    out << "Nam mua  : " << o.purchaseYear << "\n";
    return out;
}
bool Owner::operator <= (int year){
    return purchaseYear <= year;
}

/***************** Định nghĩa Lớp con Renter *****************/
istream& operator >> (istream& in, Renter &re){
    Resident r;
    in >> r;

    re.setName(r.getName());
    re.setAge(r.getAge());
    re.setApartmentNumber(r.getApartmentNumber());
    re.setPhoneNumber(r.getPhoneNumber());
    re.setEmail(r.getEmail());
    
    in >> re.price;
    return in;
}
ostream& operator << (ostream& out, Renter re){
    Resident *r = new Resident(re.getName(), re.getAge(), re.getApartmentNumber(), re.getPhoneNumber(), re.getEmail());
    out << *r;
    out << "Gia thue : " << fixed << setprecision(2) << re.price << " trieu\n";
    return out;
}
bool Renter::operator >= (double money){
    return price >= money;
}

/***************** Định nghĩa các hàm bổ trợ *****************/
void importInfo(){
    int ownAmount, rentAmount;
    cin >> ownAmount >> rentAmount;

    Owner own;
    while(ownAmount--){
        cin >> own;
        owners.push_back(own);
    }

    Renter rent;
    while(rentAmount--){
        cin >> rent;
        renters.push_back(rent);
    }

    cin >> requestType;
}

void exportInfo(){ 
    int count;
    if (!requestType){
        int year;
        cin >> year;

        cout << "Cac can ho da ban den nam " << year << ": \n";

        count = 0;
        for (auto own : owners)
            if (own <= year){
                cout << '#' << ++count << '\n';
                cout << own;
            }
    }
    else {
        double money;
        cin >> money;

        cout << "Cac can ho co gia tu " << money << " trieu: \n";

        count = 0;
        for (auto rent : renters)
            if (rent >= money){
                cout << '#' << ++count << '\n';
                cout << rent;
            }
    }

    if (!count)
        cout << "Khong tim thay!";
}