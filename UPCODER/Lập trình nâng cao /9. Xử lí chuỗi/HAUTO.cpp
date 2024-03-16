#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct Stack {
    int data[100];
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

    void push(int n) {
        if (!this->full()) 
            this->data[++this->index] = n;
        return;
    }

    int top() {
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

    string str, tmp;
    getline(cin, str);
    stringstream ss(str);

    Stack intStack; 
    intStack.init();

    while (ss >> tmp) {
        if (tmp != "*" && tmp != "+" && tmp != "-") 
            intStack.push(stoi(tmp));
        else {
            int second = intStack.top(); intStack.pop();
            int first = intStack.top(); intStack.pop();
            if (tmp == "+") 
                intStack.push(first + second);
            else if (tmp == "-")
                intStack.push(first - second);
            else if (tmp == "*")
                intStack.push(first * second);
        }
    }

    cout << intStack.top();
    return 0;
}