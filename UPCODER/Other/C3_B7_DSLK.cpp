#include <iostream>
#include <cmath>
using namespace std;

class DonThuc {
protected:
    int heSo;
    int soMu;

public:
    DonThuc() : heSo(0), soMu(0) {}
    DonThuc(int hs, int sm) : heSo(hs), soMu(sm) {}
    int getHeSo() const { return heSo; }
    int getSoMu() const { return soMu; }
    friend ostream& operator << (ostream&, const DonThuc&);
    friend DonThuc operator + (const DonThuc&, const DonThuc&);
    DonThuc daoHam() const;
};

class Node {
private:
    DonThuc donThuc;
    Node* next;

public:
    Node(const DonThuc& dt) : donThuc(dt), next(nullptr) {}
    void setNext(Node* n) { next = n; }
    Node* getNext() { return next; }
    const DonThuc& getDonThuc() const { return donThuc; }
};

class DaThuc {
private:
    Node* head;

public:
    DaThuc() : head(nullptr) {}
    ~DaThuc();
    void themDonThuc(const DonThuc& dt);
    void xuatDaThuc() const;
    double giaTriDaThuc(double x) const;
    DaThuc tongHaiDaThuc(const DaThuc& other) const;
    DaThuc daoHamDaThuc() const;
};

// Do testcase cua may cham
void nhapDaThuc(DaThuc &dt1, DaThuc &dt2, double arr[], size_t size);

int main() {
    DaThuc dt1, dt2;
    double arr[100]; 
    size_t size = 0;

    while (cin >> arr[size]) 
        size++;
    
    double x = arr[size - 1];  
    size--;  

    nhapDaThuc(dt1, dt2, arr, size);

    dt1.xuatDaThuc(); 
    cout << " ";

    dt2.xuatDaThuc(); 
    cout << endl;

    DaThuc dt3 = dt1.tongHaiDaThuc(dt2);
    DaThuc dt4 = dt3.daoHamDaThuc();

    dt4.xuatDaThuc(); 
    cout << endl;

    cout << dt3.giaTriDaThuc(x) << endl;

    dt3.xuatDaThuc();
    return 0;
}

ostream& operator << (ostream& out, const DonThuc& dt) {
    if (dt.heSo == 0) return out;

    if (dt.heSo != 0 && dt.soMu == 0) 
        out << dt.heSo;

    else if (dt.heSo == 1) {
        if (dt.soMu == 0) 
            out << 1;
        else if (dt.soMu == 1) 
            out << "x";
        else 
            out << "x^" << dt.soMu;

    } else {
        if (dt.soMu == 0) 
            out << dt.heSo;
        else if (dt.soMu == 1) 
            out << dt.heSo << "x";
        else 
            out << dt.heSo << "x^" << dt.soMu;
    }

    return out;
}

DonThuc operator + (const DonThuc& a, const DonThuc& b) {
    return DonThuc(a.getHeSo() + b.getHeSo(), a.getSoMu());
}

DonThuc DonThuc::daoHam() const {
    if (soMu == 0 || heSo == 0) 
        return DonThuc(0, 0);

    return DonThuc(heSo * soMu, soMu - 1);
}

void DaThuc::themDonThuc(const DonThuc& dt) {
    Node* newNode = new Node(dt);

    if (!head) 
        head = newNode;

    else {
        Node* last = head;
        while (last->getNext()) 
            last = last->getNext();
        last->setNext(newNode);
    }
}

void DaThuc::xuatDaThuc() const {
    bool checkOut = false;
    Node* temp = head;

    while (temp) {
        if (checkOut && temp->getDonThuc().getHeSo() > 0) 
            cout << "+" << temp->getDonThuc();

        else if (checkOut && temp->getDonThuc().getHeSo() < 0) 
            cout << temp->getDonThuc();

        else {
            checkOut = true;
            cout << temp->getDonThuc();
        }

        temp = temp->getNext();
    }
}

double DaThuc::giaTriDaThuc(double x) const {
    double result = 0;
    Node* temp = head;

    while (temp) {
        result += temp->getDonThuc().getHeSo() * pow(x, temp->getDonThuc().getSoMu());
        temp = temp->getNext();
    }

    return result;
}

DaThuc DaThuc::tongHaiDaThuc(const DaThuc& other) const {
    DaThuc result;
    Node* dt1 = head;
    Node* dt2 = other.head;
    
    while (dt1 || dt2) {
        if (dt1 && (!dt2 || dt1->getDonThuc().getSoMu() > dt2->getDonThuc().getSoMu())) {
            result.themDonThuc(dt1->getDonThuc());
            dt1 = dt1->getNext();

        } else if (dt2 && (!dt1 || dt2->getDonThuc().getSoMu() > dt1->getDonThuc().getSoMu())) {
            result.themDonThuc(dt2->getDonThuc());
            dt2 = dt2->getNext();

        } else if (dt1 && dt2 && dt1->getDonThuc().getSoMu() == dt2->getDonThuc().getSoMu()) {
            DonThuc sum = dt1->getDonThuc() + dt2->getDonThuc();
            result.themDonThuc(sum);
            dt1 = dt1->getNext();
            dt2 = dt2->getNext();
        }
    }

    return result;
}

DaThuc DaThuc::daoHamDaThuc() const {
    DaThuc result;
    Node* temp = head;

    while (temp) {
        result.themDonThuc(temp->getDonThuc().daoHam());
        temp = temp->getNext();
    }

    return result;
}

void nhapDaThuc(DaThuc &dt1, DaThuc &dt2, double arr[], size_t size) {
    size_t mid = size / 2;

    for (size_t i = 0; i < mid; i += 2) {
        DonThuc dt(arr[i], arr[i + 1]);
        dt1.themDonThuc(dt);
    }

    for (size_t i = mid; i < size; i += 2) {
        DonThuc dt(arr[i], arr[i + 1]);
        dt2.themDonThuc(dt);
    }
}

DaThuc::~DaThuc() {
    while (head) {
        Node* temp = head;
        head = head->getNext();
        delete temp;
    }
}