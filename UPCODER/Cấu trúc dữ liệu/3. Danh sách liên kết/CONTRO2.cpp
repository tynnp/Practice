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
void remove(Node *&pHead, int value);
void push_back(Node *&pHead, int value);

signed main() {
    fastIO;
    int tmp, n, k;
    Node *pHead = nullptr;
    cin >> n >> k;

    while (n--) {
        cin >> tmp;
        push_back(pHead, tmp);
    }

    remove(pHead, k);
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

void remove(Node *&pHead, int value) {
    while (pHead != nullptr && pHead->data == value) {
        Node *tmp = pHead;
        pHead = pHead->pNext;
        delete tmp;
    }
    
    if (pHead == nullptr) return;

    Node *cur = pHead;
    while (cur->pNext != nullptr) {
        if (cur->pNext->data == value) {
            Node *tmp = cur->pNext;
            cur->pNext = cur->pNext->pNext;
            delete tmp;
        } else 
            cur = cur->pNext;
    }
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