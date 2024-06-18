#include <bits/stdc++.h>
using namespace std;

template<typename T> 
struct Stack {
    T *elements;
    int index;
    int capacity;
    
    ~Stack() {
        delete[] elements;
    }
    
    void init(int n = 1000) {
        elements = new T[n];
        index = -1;
        capacity = n;
    }
   
    void push(T element) {
        if (index < capacity - 1)
            elements[++index] = element;
    }
   
    T top() {
        return elements[index];
    }
   
    void pop() {
        if (index > -1)
            index--;
    }
    
    bool empty() {
        return index == -1;
    }
    
    bool full() {
        return index == capacity - 1;
    }
};

bool toanTu(string str) {
    char c = str[0];
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int tinh(int a, int b, char c) {
    if (c == '+') return a + b;
    if (c == '-') return a - b;
    if (c == '*') return a * b;
    if (c == '/') return a / b;
} 

int main() {
    string str;
    Stack<int> s;
    s.init();
    
    while (cin >> str) {
        if (!toanTu(str)) s.push(stoi(str));
        else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            s.push(tinh(a, b, str[0]));
        } 
    }
    
    cout << s.top();
    return 0;
}