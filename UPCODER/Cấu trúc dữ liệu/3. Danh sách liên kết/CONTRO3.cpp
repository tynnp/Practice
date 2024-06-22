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

int size(Node *pHead);
void print(Node *pHead);
void clear(Node *&pHead);
void insert(Node *&pHead, int pos, int value);
void push_back(Node *&pHead, int value);

signed main() {
    fastIO;
    int tmp, n, value, pos;
    Node *pHead = nullptr;
    cin >> n >> value >> pos;

    while (n--) {
        cin >> tmp;
        push_back(pHead, tmp);
    }

    insert(pHead, pos-1, value);
    cout << size(pHead) << endl;
    print(pHead);

    clear(pHead);
    return 0;
} 

int size(Node *pHead) {
    int res = 0;
    while (pHead != nullptr) {
        res += 1;
        pHead = pHead->pNext;
    }
    return res;
}

void print(Node *pHead) {
    while (pHead != nullptr) {
        cout << pHead->data << " ";
        pHead = pHead->pNext;
    }
}

void clear(Node *&pHead) {
    while (pHead != nullptr) {
        Node *tmp = pHead;
        pHead = pHead->pNext;
        delete tmp;
    }
    pHead = nullptr;
}

void insert(Node *&pHead, int pos, int value) {
    int index = 0;
    Node *cur = pHead;
    Node *node = new Node(value);

    if (pos == 0) {
        node->pNext = pHead;
        pHead = node;
        return;
    }

    while (index != pos-1 && cur != nullptr) {
        index += 1;
        cur = cur->pNext;
    }

    if (cur == nullptr) return;
    node->pNext = cur->pNext;
    cur->pNext = node;
}

void push_back(Node *&pHead, int value) {
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