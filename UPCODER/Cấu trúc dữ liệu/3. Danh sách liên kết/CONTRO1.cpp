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
    Node(int data): data(data), pNext(nullptr) {}
};

void push_back(Node *&pHead, int data);
int max_element(Node *pHead);
int min_element(Node *pHead);
void index_of(Node *pHead, int value);
void delete_list(Node *&pHead);

signed main() {
    fastIO;
    int tmp, n;
    Node *pHead = nullptr;

    cin >> n;
    while (n--) {
        cin >> tmp;
        push_back(pHead, tmp);
    }

    const int MAX = max_element(pHead);
    const int MIN = min_element(pHead);

    cout << MAX << endl;
    index_of(pHead, MAX);
    
    cout << MIN << endl;
    index_of(pHead, MIN);

    delete_list(pHead);
    return 0;
} 

void push_back(Node *&pHead, int data) {
    Node *node = new Node(data);

    if (pHead == nullptr) {
        pHead = node;
        return;
    }

    Node *tmp = pHead;
    while (tmp->pNext != nullptr) 
        tmp = tmp->pNext;
    tmp->pNext = node;
}

int max_element(Node *pHead) {
    int res = INT_MIN;

    while (pHead != nullptr) {
        if (pHead->data > res)
            res = pHead->data;
        pHead = pHead->pNext;
    }

    return res;
}

int min_element(Node *pHead) {
    int res = INT_MAX;

    while (pHead != nullptr) {
        if (pHead->data < res)
            res = pHead->data;
        pHead = pHead->pNext;
    }

    return res;
}

void index_of(Node *pHead, int value) {
    int index = 1;
    while (pHead != nullptr) {
        if (pHead->data == value)   
            cout << index << " ";
        index += 1;
        pHead = pHead->pNext;
    } 
    cout << endl;
}

void delete_list(Node *&pHead) {
    while (pHead != nullptr) {
        Node *tmp = pHead;
        pHead = pHead->pNext;
        delete tmp;
    }
}