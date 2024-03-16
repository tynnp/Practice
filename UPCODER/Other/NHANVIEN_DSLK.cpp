#include <iostream>
#define endl '\n'
#define ll long long  
using namespace std;

struct NhanVien {
    string maNhanVien;
    string tenNhanVien;
    ll luongNhanVien;
    friend istream& operator >> (istream&, NhanVien&);
    friend ostream& operator << (ostream&, NhanVien);
};

struct Node {
    NhanVien data;
    Node* next;
    Node(NhanVien nv): data(nv), next(nullptr) {}
};

struct LinkedList {
    Node* head;
    LinkedList(): head(nullptr) {}
    void pushBack(NhanVien);
    string nvLuongCaoNhat();
    ll tongLuong();
    void sapXepGiamDan();
    NhanVien nvLuongThapNhat();
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LinkedList list;
    int n; cin >> n;
    cin.ignore();
    bool checkEnd = false;
 
    while (n--) {
        NhanVien nv;
        if (checkEnd) cout << endl;

        cin >> nv;
        checkEnd = true;

        list.pushBack(nv);
        cout << nv;
    }

    cout << endl << list.nvLuongCaoNhat() << endl;
    cout << list.tongLuong() << endl;
    list.sapXepGiamDan();
    cout << list.nvLuongThapNhat();

    return 0;
}

istream& operator >> (istream& in, NhanVien& nv) {
    getline(in, nv.maNhanVien);
    getline(in, nv.tenNhanVien);
    in >> nv.luongNhanVien; in.ignore();
}

ostream& operator << (ostream& out, NhanVien nv) {
    out << "{" << nv.tenNhanVien << ", " << nv.maNhanVien;
    out << ", " << nv.luongNhanVien << "}"; 
}

void LinkedList::pushBack(NhanVien nv) {
    Node* node = new Node(nv);

    if (this->head == nullptr)
        this->head = node;
    else {
        Node* tmp = this->head;
        while (tmp->next != nullptr)
            tmp = tmp->next;
        tmp->next = node;
    }

    return;
}

string LinkedList::nvLuongCaoNhat() {
    int luongMax = 0;

    Node* x = this->head;
    while (x != nullptr) {
        if (x->data.luongNhanVien > luongMax) 
            luongMax = x->data.luongNhanVien;
        x = x->next;
    }

    Node* y = this->head;
    while (y != nullptr) {
        if (y->data.luongNhanVien == luongMax) 
            return y->data.tenNhanVien;
        y = y->next;
    }
} 

ll LinkedList::tongLuong() {
    ll result = 0;
    Node* tmp = this->head;

    while (tmp != nullptr) 
        result += tmp->data.luongNhanVien,
        tmp = tmp->next;

    return result;
}

void LinkedList::sapXepGiamDan() {
    bool swapped;
    Node* last = nullptr;
    do {
        swapped = false;
        Node* x = head;

        while (x->next != last) {
            if (x->data.luongNhanVien < x->next->data.luongNhanVien) {
                NhanVien tmp = x->data;
                x->data = x->next->data;
                x->next->data = tmp;
                swapped = true;
            }
            x = x->next;
        }
        last = x;
    } while (swapped);
}

NhanVien LinkedList::nvLuongThapNhat() {
    while (head->next != nullptr) 
        head = head->next;
    return head->data;
}