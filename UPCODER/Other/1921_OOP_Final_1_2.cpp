#include <iostream>
using namespace std;

class Device {
private:
    string model;
    string manufactory;
    int power;
    double cost;

public:
    // Hàm khởi tạo
    Device();                                                           // Khởi tạo mặc định
    Device(string model, string manufactory, int power, double cost);   // Khởi tạo có tham số
    Device(const Device &other);                                        // Sao chép
    
    string getModel();
    double getTotalCost();

    friend istream &operator >> (istream &aaa, Device &de);
    friend ostream &operator << (ostream &aaa, Device de);

    bool operator < (Device other);
    bool operator > (Device other);
    bool operator == (Device other);
    double operator * (int number);
};

Device find(Device list[], int n, string model);

int main() {
    int n;
    double tongTien = 0;
    cin >> n;

    Device list[n];

    // Nhập và tính tổng tiền của n Device
    for (int i = 0; i < n; i++) {
        int number;
        cin >> list[i] >> number;
        tongTien += list[i] * number;
    }

    // Xuất ra tổng tiền
    cout << tongTien << endl;
    
    // Nhập model s và t đề bài cho
    string s, t;
    cin >> s >> t;

    // Tìm kiếm thiết bị có model là s, lưu thiết bị đó vào a
    Device a = find(list, n, s);

    // Tìm kiếm thiết bị có model là t, lưu thiết bị đó vào b
    Device b = find(list, n, t);

    // So sánh 2 thiết bị a (có model là s) và b (có model t)
    if (a > b) cout << '>';
    else if (a < b) cout << '<';
    else cout << '=';

    return 0;
}

// Hàm khởi tạo mặc định
Device::Device() {
    model = manufactory = "";
    power = cost = 0;
}

// Hàm khởi tạo có tham số (cách 1)
Device::Device(string model, string manufactory, int power, double cost) {
    this->model = model;
    this->manufactory = manufactory;
    this->power = power;
    this->cost = cost;
}

// Hàm khởi tạo có tham số (cách 2)
// Device::Device(string model, string manufactory, int power, double cost): 
//     model(model), manufactory(manufactory), power(power), cost(cost) {}

// Hàm sao chép
Device::Device(const Device &other) {
    model = other.model;
    manufactory = other.manufactory;
    power = other.power;
    cost = other.cost;
}

// Lấy model của thiết bị
string Device::getModel() {
    return model;
}

double Device::getTotalCost() {
    double totalCost = cost + cost * 0.1;
    return totalCost;
}

// Quá tải nhập
istream &operator >> (istream &aaa, Device &de) {
    aaa >> de.model >> de.manufactory >> de.power >> de.cost;
    return aaa;
}

// Quá tải xuất
ostream &operator << (ostream &aaa, Device de) {
    aaa << de.model + "-" + de.manufactory + "-";
    aaa << de.power << "W-" << de.getTotalCost();
    aaa << endl;
    return aaa;
}

bool Device::operator < (Device other) {
    return power < other.power;
}

bool Device::operator > (Device other) {
    return power > other.power;
}

bool Device::operator == (Device other) {
    return power == other.power;
}

double Device::operator * (int number) {
    return getTotalCost() * number;
}

// Hàm tìm thiết bị có model là model trong mảng list có n phần tử
Device find(Device list[], int n, string model) {
    for (int i = 0; i < n; i++)
        if (list[i].getModel() == model)    // nếu model của thiết bị bằng model cần tìm
            return list[i];                 // trả về thiết bị cần tìm
}

/* Ghi chú
    => Khai báo lớp (Clas):
        - Biến (thuộc tính) => private.
        - Hàm (phương thức) => public.

    => TH Class B kế thừa từ Class A:
        - Biến (Class A) => protected (để cho Class B truy cập).
        - Biến (Class B) => private.
*/