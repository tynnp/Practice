#include <iostream>
using namespace std;

class Set {
private:
    int *elements;  // Con trỏ quản lý các phần tử trong set 
    int size;       // Số phần tử hiện tại của set
    int capacity;   // Sức chứa tối đa của set

public:
    Set();                  // Hàm khởi tạo mặc định
    Set(int n);             // Hàm khởi tạo 1 tham số
    Set(int a, int b);      // Hàm khởi tạo 2 tham số
    Set(const Set &other);  // Hàm khởi tạo sao chép
    
    bool Contain(int x);    // Kiểm tra tập hợp có chứa x không
    bool Add(int x);        // Thêm x vào tập hợp
    bool Remove(int x);     // Xóa x khỏi tập hợp

    Set operator & (Set other);     // Phép toán and
    Set operator | (Set other);     // Phép toán or
    friend ostream &operator << (ostream &out, Set set);    // In set
};

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    Set setA(n), setB(a, b);

    cout << (setA | setB) << endl;
    cout << (setA & setB) << endl;
    
    return 0;
}

Set::Set() {
    size = 0;   // Tập rỗng không có phần tử
    capacity = 10;  
    elements = new int[capacity];
}

Set::Set(int n) {
    if (n > 0) {
        size = n;   
        capacity = n;
        elements = new int[capacity];

        // N phần tử giá trị từ 1 đến N
        for (int i = 0; i < n; i++) 
            elements[i] = i + 1;
        
    } else {
        size = 0;
        capacity = 10;
        elements = new int[capacity];
    }
}

Set::Set(int a, int b) {
    if (a <= b) {
        size = b - a + 1;
        capacity = size;
        elements = new int[capacity];

        // b - a + 1 phần tử giá trị từ a đến b
        for (int i = 0; i < size; i++) 
            elements[i] = a + i;
        
    } else {
        size = 0;
        capacity = 10;
        elements = new int[capacity];
    }
}

Set::Set(const Set &other) {
    size = other.size;
    capacity = other.capacity;
    elements = new int[capacity];

    for (int i = 0; i < size; i++) 
        elements[i] = other.elements[i];
}

bool Set::Contain(int x) {
    for (int i = 0; i < size; i++)
        if (elements[i] == x)
            return true;
    return false;
}

bool Set::Add(int x) {
    if (Contain(x)) 
        return false;   // Nếu x đã có trong set thì false
    
    // Nếu set đã đầy thì mở rộng sức chứa
    if (size == capacity) {
        capacity *= 2;
        int *newElements = new int[capacity];

        for (int i = 0; i < size; i++)
            newElements[i] = elements[i];

        delete[] elements;
        elements = newElements;
    }
    
    // Thêm x vào set
    elements[size++] = x;
    return true;
}

bool Set::Remove(int x) {
    for (int i = 0; i < size; i++) {
        if (elements[i] == x) {
            for (int j = i; j < size - 1; j++)
                elements[j] = elements[j + 1];

            size--;
            return true;
        }
    }

    return false;
}

// Phép and, trả về set chứa các phần tử có trong cả 2 set
Set Set::operator & (Set other) {
    Set res;
    for (int i = 0; i < size; i++) 
        if (other.Contain(elements[i]))
            res.Add(elements[i]);
    return res;
}

// Phép or, trả về set chứa các phần tử nằm trong ít nhất 1 set
Set Set::operator | (Set other) {
    Set res = *this;
    for (int i = 0; i < other.size; i++)
        res.Add(other.elements[i]);
    return res;
} 

ostream &operator << (ostream &out, Set set) {
    if (set.size == 0) {
        out << "NULL";
        return out;
    }

    // Sắp xếp tăng dần trước khi xuất
    for (int i = 1; i < set.size; i++) {
        int j = i;
        while (j > 0 && set.elements[j-1] > set.elements[j]) {
            swap(set.elements[j-1], set.elements[j]);
            j--;
        }
    }

    for (int i = 0; i < set.size; i++)
        out << set.elements[i] << " ";
    return out;
}