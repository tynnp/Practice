#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

struct Node {
    char data;
    Node *pNext;
    Node(char value): data(value), pNext(nullptr) {}
};

void clear(Node *&pHead);
void print(Node *pHead);
void solve(Node *&pHead);
void push_back(Node *&pHead, char value);

signed main() {
    fastIO;
    char c;
    Node *pHead = nullptr;

    while (cin >> c)
        push_back(pHead, c);

    solve(pHead);   
    print(pHead);
    clear(pHead);
    return 0;
} 

void clear(Node *&pHead) {
    while (pHead != nullptr) {
        Node *tmp = pHead;
        pHead = pHead->pNext;
        delete tmp;
    }
}

void print(Node *pHead) {
    while (pHead != nullptr) {
        cout << pHead->data << " ";
        pHead = pHead->pNext;
    }
}

void solve(Node *&pHead) {
    if (pHead == nullptr) return;
    Node *prev = pHead;
    Node *cur = pHead->pNext;

    while (cur != nullptr) {
        if (prev->data > cur->data) {
            Node *tmp = cur;
            prev->pNext = cur->pNext;
            cur = cur->pNext;
            delete tmp;
        } else {
            prev = cur;
            cur = cur->pNext;
        }
    }
}

void push_back(Node *&pHead, char value) {
    Node *node = new Node(value);

    if (pHead == nullptr) {
        pHead = node;
        return;
    }

    Node *tmp = pHead;
    while (tmp->pNext != nullptr) 
        tmp = tmp->pNext;
    tmp->pNext = node;
}