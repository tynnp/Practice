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
bool empty(Node *pHead);
void clear(Node *&pHead);
void print(Node *pHead);
void solve(Node *pHead);
void push_back(Node *&pHead, int value);

signed main() {
    fastIO;
    int tmp, n;
    Node *pHead = nullptr;
    cin >> n;

    while (n--) {
        cin >> tmp;
        push_back(pHead, tmp);
    }

    solve(pHead);
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

bool empty(Node *pHead) {
    return pHead == nullptr;
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

    if (pHead == nullptr) {
        pHead = node;
        return;
    }

    Node *tmp = pHead;
    while (tmp->pNext != nullptr) 
        tmp = tmp->pNext;
    tmp->pNext = node;
}

void print(Node *pHead) {
    while (pHead != nullptr) {
        cout << pHead->data << " ";
        pHead = pHead->pNext;
    }
}

void solve(Node *pHead) {
    Node *ans = nullptr;
    int index = 2;

    if (size(pHead) < 2) {
        cout << -1;
        return;
    }

    Node *a = pHead;
    Node *b = a->pNext;
    Node *c = b->pNext;

    while (c != nullptr) {
        if (b->data == a->data * c->data) 
            push_back(ans, index);
        a = a->pNext;
        b = b->pNext;
        c = c->pNext;
        index += 1;
    }

    if (empty(ans)) cout << -1;
    else {
        cout << size(ans) << endl;
        print(ans);
    }
}