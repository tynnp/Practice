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
    
    double getTotalCost();

    friend istream &operator >> (istream &aaa, Device &de);
    friend ostream &operator << (ostream &aaa, Device de);
};

int main() {
    int n;
    cin >> n;

    Device list[n];

    for (int i = 0; i < n; i++)
        cin >> list[i];
    
    for (int i = 0; i < n; i++)
        cout << list[i];

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


/* Ghi chú
    => Khai báo lớp (Clas):
        - Biến (thuộc tính) => private.
        - Hàm (phương thức) => public.

    => TH Class B kế thừa từ Class A:
        - Biến (Class A) => protected (để cho Class B truy cập).
        - Biến (Class B) => private.
*/