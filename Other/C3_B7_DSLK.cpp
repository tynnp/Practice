#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class DonThuc {
protected:
    int heSo;
    int soMu;
public:
    DonThuc(){} DonThuc(int, int);
    int getHeSo(); int getSoMu();
    friend ostream& operator << (ostream&, DonThuc);
    friend DonThuc operator + (DonThuc, DonThuc);
    static DonThuc daoHam(DonThuc);
};

class Node {
private:
    DonThuc donThuc;
    Node* next;
public:
    static void xuatDaThuc(Node*);
    static void themDonThuc(Node*&, DonThuc);
    static void nhapDaThuc(Node*&, Node*&, vector<double>);
    static Node* daoHamDaThuc(Node*);
    static Node* tongHaiDaThuc(Node*, Node*);
    static double giaTriDaThuc(Node*, double x);
};

int main() {
    Node *dt1 = NULL, *dt2 = NULL;
    double n; vector<double> vt;

    while (cin >> n) vt.push_back(n);
    double x; x = vt.back();

    Node::nhapDaThuc(dt1, dt2, vt);
    Node::xuatDaThuc(dt1); cout << " ";
    Node::xuatDaThuc(dt2); cout << endl;
    Node* dt3 = Node::tongHaiDaThuc(dt1, dt2); 
    Node* dt4 = Node::daoHamDaThuc(dt3);
    Node::xuatDaThuc(dt4); cout << endl;
    cout << Node::giaTriDaThuc(dt3, x); cout << endl;
    Node::xuatDaThuc(dt3);
    return 0;
}

DonThuc::DonThuc(int heSo, int soMu) {
    this->heSo = heSo;
    this->soMu = soMu;
}

int DonThuc::getHeSo() {
    return heSo;
}

int DonThuc::getSoMu() {
    return soMu;
}

ostream& operator << (ostream& out, DonThuc dt) {
    if (dt.heSo == 0) return out;
    else if (dt.heSo == 1) {
        if (dt.soMu == 0) cout << 1;
        else if (dt.soMu == 1) cout << "x";
        else cout << "x^" << dt.soMu;
    } else if (dt.heSo != 1) {
        if (dt.soMu == 0) cout << abs(dt.heSo);
        else if (dt.soMu == 1) cout << abs(dt.heSo) << "x";
        else cout << abs(dt.heSo) << "x^" << dt.soMu;       
    }
}

DonThuc operator + (DonThuc a, DonThuc b) {
    DonThuc c;
    c.soMu = a.getSoMu();
    c.heSo = a.getHeSo() + b.getHeSo();
    return c;
}

DonThuc DonThuc::daoHam(DonThuc dt) {
    DonThuc res;
    if (dt.soMu == 0 || dt.heSo == 0) res.soMu = 0, res.heSo = 0;
    else if (dt.soMu == 1) res.soMu = 0, res.heSo = dt.heSo;
    else res.heSo = dt.heSo*dt.soMu, res.soMu = dt.soMu - 1;
    return res;
} 

void Node::themDonThuc(Node*& head, DonThuc dt) {
    Node* newNode = new Node;
    newNode->donThuc = dt;
    newNode->next = NULL;
    if (head == nullptr) 
        head = newNode;
    else {
        Node* last = head;
        while (last->next != nullptr) 
            last = last->next;
        last->next = newNode;
    }
}

void Node::xuatDaThuc(Node* head) {
    bool checkOut = false;
    while (head != nullptr) {
        if (checkOut && head->donThuc.getHeSo() > 0) 
            cout << "+" << head->donThuc;
        else if (checkOut && head->donThuc.getHeSo() < 0)
            cout << "-" << head->donThuc;
        else {
            checkOut = true;
            cout << head->donThuc;
        }
        head = head->next;
    } 
}

double Node::giaTriDaThuc(Node* head, double x) {
    double result = 0;
    while (head != nullptr) {
        result += head->donThuc.getHeSo()*pow(x, head->donThuc.getSoMu());
        head = head->next;
    }
    return result;
}

void Node::nhapDaThuc(Node*& dt1, Node*& dt2, vector<double> vt) {
    vector<double>::iterator it; 
    it = vt.end()-1; vt.erase(it);

    for (int i = 0; i < vt.size()/2; i += 2) {
        DonThuc dt(vt[i], vt[i+1]);
        themDonThuc(dt1, dt);
    }

    for (int i = vt.size()/2; i < vt.size(); i += 2) {
        DonThuc dt(vt[i], vt[i+1]);
        themDonThuc(dt2, dt);
    }
}

Node* Node::tongHaiDaThuc(Node* dt1, Node* dt2) {
    int soMuMax = 0;
    Node *a = dt1, *b = dt2;
    while (a != nullptr) {
        if (soMuMax < a->donThuc.getSoMu())
            soMuMax = a->donThuc.getSoMu();
        a = a->next;
    }
    while (b != nullptr) {
        if (soMuMax < b->donThuc.getSoMu())
            soMuMax = b->donThuc.getSoMu();
        b = b->next;
    }

    Node* dt3 = NULL;
    while (soMuMax > -1) {
        Node* x = dt1, *y = dt2;
        while (x != nullptr && x->donThuc.getSoMu() != soMuMax)
            x = x->next;
        while (y != nullptr && y->donThuc.getSoMu() != soMuMax)
            y = y->next;

        if (x != nullptr && y != nullptr) {
            DonThuc z = x->donThuc + y->donThuc;
            themDonThuc(dt3, z);
        } else if (x != nullptr) themDonThuc(dt3, x->donThuc);
        else if (y != nullptr) themDonThuc(dt3, y->donThuc);
        soMuMax--;
    } return dt3;
}

Node* Node::daoHamDaThuc(Node* head) {
    Node* res = NULL;
    while (head != nullptr) {
        themDonThuc(res, DonThuc::daoHam(head->donThuc)); 
        head = head->next; 
    } return res;
}