#include <iostream>
using namespace std;

class BankAccount {
protected:
    string ID;
    string CustomerName;
    string IDCardNumber;
    double Balance;
public:
    BankAccount() {
        ID = "000000";
        CustomerName = "No name";
        IDCardNumber = "xxx";
        Balance = 0;
    }

    BankAccount(string id, string customerName, string idCardNumber, double money) {
        this->ID = id;
        this->CustomerName = customerName;
        this->IDCardNumber = idCardNumber;
        this->Balance = money;
    }   

    double getBalance() {
        return this->Balance;
    }

    void setBalance(double money) {
        this->Balance = money;
        return;
    }

    string ToString() {
        return "{" + this->ID + "}:{" + this->CustomerName + "}:{" + to_string( (int) this->Balance) + "}";
    }

    virtual double WithdrawLimit() {
        return this->Balance;
    }

    virtual bool Withdraw(double withdrawmoney) {
        return withdrawmoney <= this->WithdrawLimit();
    }

    virtual double Deposit(double depositmoney) {
        Balance += depositmoney;
        return this->Balance;
    }
};

class CheckingAccount : public BankAccount {
private:
    double OverDraftLimit;
public: 
    CheckingAccount() : BankAccount() {
        this->OverDraftLimit = 50000;
    }

    CheckingAccount(string id, string customerName, string idCardNumber, double money, double overDraftLimit) : 
        BankAccount(id, customerName, idCardNumber, money) {
            this->OverDraftLimit = overDraftLimit;
        }

    double WithdrawLimit() override {
        return this->Balance + this->OverDraftLimit;
    }

    bool Withdraw(double withdrawmoney) override {
        return withdrawmoney <= this->WithdrawLimit();
    }
};

class SavingAccount : public BankAccount {
private:
    double InterestRate;
    double InterMoney;
public:
    SavingAccount() : BankAccount() {}

    SavingAccount(string id, string customerName, string idCardNumber, double money) : 
        BankAccount(id, customerName, idCardNumber, money) {}

    double getInterMoney() {
        return this->InterMoney;
    }

    double WithdrawLimit() override {
        return this->Balance;
    }

    double Deposit(double depositmoney) override {
        if (this->Balance < 1000000) this->InterestRate = 0.1;
        else if (this->Balance < 50000000) this->InterestRate = 0.3;
        else if (this->Balance < 200000000) this->InterestRate = 0.5;
        else if (this->Balance < 1000000000) this->InterestRate = 1;
        else this->InterestRate = 1.94;
        this->InterMoney = this->Balance*this->InterestRate;
        return this->Balance;
    }
};

int main() {
    char c; 
    string thongTin;
    double tienRut;
    CheckingAccount a;
    SavingAccount b;
    cin >> c >> thongTin >> tienRut;

    string id, customerName, idCardNumber;
    double money, overDraftLimit;
    int start = 0, end;

    thongTin += '/';
    end = thongTin.find('/', start);
    id = thongTin.substr(start, end-start); start = end+1;

    end = thongTin.find('/', start);
    customerName = thongTin.substr(start, end-start); start = end+1;

    end = thongTin.find('/', start);
    idCardNumber = thongTin.substr(start, end-start); start = end+1;

    end = thongTin.find('/', start);
    money = stod(thongTin.substr(start, end-start)); start = end+1;

    if (c == 'C') {
        end = thongTin.find('/', start);
        overDraftLimit = stod(thongTin.substr(start, end-start));
        a = CheckingAccount(id, customerName, idCardNumber, money, overDraftLimit);

        cout << a.ToString() << endl;
        if (a.Withdraw(tienRut)) {
            a.setBalance(a.getBalance() - tienRut);
            cout << "Yes " << a.ToString() << endl; 
        } else cout << "No\n";
        cout << "Checking Account";

    } else if (c == 'S') {
        b = SavingAccount(id, customerName, idCardNumber, money);

        cout << b.ToString() << endl;
        if (b.Withdraw(tienRut)) {
            b.setBalance(b.getBalance() - tienRut);
            cout << "Yes " << b.ToString() << endl; 
        } else cout << "No\n";
        b.Deposit(b.getBalance());
        b.setBalance(b.getBalance() + b.getInterMoney());
        cout << b.ToString();
    }

    return 0;
}