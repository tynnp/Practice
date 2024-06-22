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

void push_back(Node *&pHead, int value);
bool solve(Node *pHead);
void clear(Node *&pHead);

signed main() {
    fastIO;
    int tmp, n;
    Node *pHead = nullptr;
    cin >> n;

    while (n--) {
        cin >> tmp;
        push_back(pHead, tmp);
    }

    cout << (solve(pHead) ? "YES" : "NO");
    clear(pHead);
    return 0;
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

bool solve(Node *pHead) {
    Node *a = pHead;
    while (a != nullptr) {

        Node *b = pHead;
        while (b != nullptr) {

            Node *c = b->pNext;
            while (c != nullptr) {
                if (a->data == b->data + c->data)
                    return true;
                c = c->pNext;
            }
            b = b->pNext;
        }
        a = a->pNext;
    }

    return false;
}

void clear(Node *&pHead) {
    while (pHead != nullptr) {
        Node *tmp = pHead;
        pHead = pHead->pNext;
        delete tmp;
    }
    pHead = nullptr;
}