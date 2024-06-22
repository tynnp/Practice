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
    int data;
    Node *pNext;
    Node(int value): data(value), pNext(nullptr) {}
};

bool empty(Node *pHead);
int front(Node *pHead);
void clear(Node *&pHead);
void push_back(Node *&pHead, int value);
void push_front(Node *&pHead, int value);
void pop_front(Node *&pHead);

signed main() {
    fastIO;
    int n, k;
    Node *pHead = nullptr;
    cin >> n >> k;

    if (k > 0) {
        for (int i = 0; i < n; i++)
            push_back(pHead, i);
    } else {
        for (int i = 1; i < n; i++)
            push_front(pHead, i);
        push_front(pHead, 0);
    }

    k = abs(k);
    while (!empty(pHead)) {
        for (int i = 1; i < k; i++) {
            push_back(pHead, front(pHead));
            pop_front(pHead);
        }

        cout << front(pHead) << " ";
        pop_front(pHead);
    }

    clear(pHead);
    return 0;
} 

bool empty(Node *pHead) {
    return pHead == nullptr;
}

int front(Node *pHead) {
    return pHead->data;
}

void clear(Node *&pHead) {
    while (pHead != nullptr) {
        Node *tmp = pHead;
        pHead = pHead->pNext;
        delete tmp;
    }
}

void push_back(Node *&pHead, int value) {
    Node *node = new Node(value);
    Node *tmp = pHead;

    if (pHead == nullptr) {
        pHead = node;
        return;
    }

    while (tmp->pNext != nullptr) 
        tmp = tmp->pNext;
    tmp->pNext = node;
}

void push_front(Node *&pHead, int value) {
    Node *node = new Node(value);
    node->pNext = pHead;
    pHead = node;
}

void pop_front(Node *&pHead) {
    Node *tmp = pHead;
    pHead = pHead->pNext;
    delete tmp;
}