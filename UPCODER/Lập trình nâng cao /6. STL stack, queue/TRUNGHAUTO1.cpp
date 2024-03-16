#include <iostream>
#include <map>
using namespace std;

struct Stack {
    char data[100];
    int index;

    void init() {
        this->index = -1;
        return;
    }

    bool empty() {
        return this->index == -1;
    }

    bool full() {
        return this->index == 99;
    }

    void push(char c) {
        if (!this->full()) 
            this->data[++this->index] = c;
        return;
    }

    char top() {
        if (!this->empty())
            return this->data[this->index];
        return -1;
    }

    void pop() {
        if (!this->empty())
            --this->index;
        return;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    map<char, int> mapChar = {{'*', 2}, {'/', 2}, {'+', 1}, {'-', 1}};
    Stack st; st.init();
    char tmp;

    while (cin >> tmp) {
        if (tmp >= '0' && tmp <= '9') cout << tmp << " ";

        else if (st.empty() || tmp == '(') st.push(tmp);

        else if (tmp == ')') {
            while (st.top() != '(') {
                cout << st.top() << " ";
                st.pop();
            }
            st.pop();

        } else if (mapChar[tmp] <= mapChar[st.top()]) {
            cout << st.top() << " ";
            st.pop();
            st.push(tmp);

        } else st.push(tmp);
    }

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}