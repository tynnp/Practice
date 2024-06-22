#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("CONTRO.inp", "r", stdin)
#define out freopen("CONTRO.out", "w", stdout)
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
void clear(Node *&pHead);
void print(Node *pHead);
void push_back(Node *&pHead, int value);
int distance_min(Node *pHead);
void solve(Node *pHead);

signed main() {
    fastIO; inp; out;
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

void clear(Node *&pHead) {
    while (pHead != nullptr) {
        Node *tmp = pHead;
        pHead = pHead->pNext;
        delete tmp;
    }
    pHead = nullptr;
}

void print(Node *pHead) {
    while (pHead != nullptr) {
        int minVal = min(pHead->data, pHead->pNext->data);
        int maxVal = max(pHead->data, pHead->pNext->data);
        cout << "(" << minVal << ", " << maxVal << ") ";
        pHead = pHead->pNext->pNext;
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

int distance_min(Node *pHead) {
    if (size(pHead) < 2) return -1;
    int res = abs(pHead->data - pHead->pNext->data);
    Node *prev = pHead;

    while (prev != nullptr) {
        Node *cur = prev->pNext;
        while (cur != nullptr) {
            int distance = abs(cur->data - prev->data);
            if (distance < res) res = distance;
            cur = cur->pNext;
        }
        prev = prev->pNext;
    }

    return res;
}

void solve(Node *pHead) {
    Node *ans = nullptr;
    int distance = distance_min(pHead);
    
    Node *prev = pHead;
    while (prev != nullptr) {

        Node *cur = prev->pNext;
        while (cur != nullptr) {
            if (abs(cur->data - prev->data) == distance) {
                push_back(ans, prev->data);
                push_back(ans, cur->data);
            }
            cur = cur->pNext;
        }
        prev = prev->pNext;
    }

    cout << size(ans)/2 << " " << distance << endl;
    print(ans);
}