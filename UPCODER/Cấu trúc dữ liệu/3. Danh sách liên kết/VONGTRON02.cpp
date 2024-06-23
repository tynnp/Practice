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

void clear(Node *&pHead);
bool empty(Node *pHead);
int front(Node *pHead);
void pop_front(Node *&pHead);
void push_back(Node *&pHead, int value);

signed main() {
    fastIO;
    int n, m, tmp;
    Node *pHead = nullptr;
    Node *k = nullptr;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        push_back(pHead, i);

    while (m--) {
        cin >> tmp;
        push_back(k, tmp);
    }

    while (!empty(pHead)) {
        m = front(k);
        push_back(k, m);
        pop_front(k);

        for (int i = 1; i < m; i++) {
            push_back(pHead, front(pHead));
            pop_front(pHead);
        }

        cout << front(pHead) << " ";
        pop_front(pHead);
    }

    clear(pHead);
    clear(k);
    return 0;
} 

void clear(Node *&pHead) {
    while (pHead != nullptr) {
        Node *tmp = pHead;
        pHead = pHead->pNext;
        delete tmp;
    }
}

bool empty(Node *pHead) {
    return pHead == nullptr;
}

int front(Node *pHead) {
    if (!empty(pHead))
        return pHead->data;
}

void pop_front(Node *&pHead) {
    Node *tmp = pHead;
    pHead = pHead->pNext;
    delete tmp;
}

void push_back(Node *&pHead, int value) {
    Node *node = new Node(value);

    if (empty(pHead)) {
        pHead = node;
        return;
    }

    Node *tmp = pHead;
    while (tmp->pNext != nullptr) 
        tmp = tmp->pNext;
    tmp->pNext = node;
}
