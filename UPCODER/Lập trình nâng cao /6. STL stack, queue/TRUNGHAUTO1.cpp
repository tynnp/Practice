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

int priority(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int main() {
    char c;
    Stack<char> s;
    s.init();
    
    while (cin >> c) {
        if (isalnum(c)) cout << c << " ";
        else if (c == '(') s.push(c);
        
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                cout << s.top() << " ";
                s.pop();
            }
            
            if (!s.empty()) s.pop();
        }
        
        else {
            while (!s.empty() && priority(s.top()) >= priority(c)) {
                cout << s.top() << " ";
                s.pop();
            }
            s.push(c);
        }
    }
    
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    
    return 0;
}