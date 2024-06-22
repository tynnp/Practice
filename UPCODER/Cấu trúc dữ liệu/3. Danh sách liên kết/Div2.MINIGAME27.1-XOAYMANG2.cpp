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
void print(Node *pHead);
void clear(Node *&pHead, Node *&pTail);
void push_back(Node *&pHead, Node *&pTail, int value);
void rotate_left(Node *&pHead, Node *&pTail, int k);

signed main() {
    fastIO;
    int tmp, n, k;
    Node *pHead = nullptr;
    Node *pTail = nullptr;

    cin >> n >> k;
    k = k % n;

    while (n--) {
        cin >> tmp;
        push_back(pHead, pTail, tmp);
    }

    rotate_left(pHead, pTail, k);
    print(pHead);
    clear(pHead, pTail);
    return 0;
} 

bool empty(Node *pHead) {
    return pHead == nullptr;
}

void print(Node *pHead) {
    while (pHead != nullptr) {
        cout << pHead->data << " ";
        pHead = pHead->pNext;
    }
}

void clear(Node *&pHead, Node *&pTail) {
    while (pHead != nullptr) {
        Node *tmp = pHead;
        pHead = pHead->pNext;
        delete tmp;
    }

    pHead = nullptr;
    pTail = nullptr;
}

void push_back(Node *&pHead, Node *&pTail, int value) {
    Node *node = new Node(value);

    if (pHead == nullptr) {
        pHead = node;
        pTail = node;
        return;
    }

    pTail->pNext = node;
    pTail = node;
}

void rotate_left(Node *&pHead, Node *&pTail, int k) {
    if (empty(pHead) || k == 0) return;
    Node *cur = pHead;
    int cnt = 1;

    while (cnt < k && cur != nullptr) {
        cur = cur->pNext;
        cnt += 1;
    }

    if (cur == nullptr || cur->pNext == nullptr) return;

    Node *new_Head = cur->pNext;
    cur->pNext = nullptr;
    pTail->pNext = pHead;
    pHead = new_Head;
}