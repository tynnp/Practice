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
void solve(Node *list, Node *num); 
void delete_list(Node *&pHead); 

signed main() {
    fastIO;
    int n; 
    Node *list = nullptr;
    Node *num = nullptr;

    while (cin >> n) 
        push_back(num, n);
    
    for (int i = 0; i <= 9; i++) 
        push_back(list, i);

    solve(list, num);
    delete_list(list);
    delete_list(num);
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

void solve(Node *list, Node *num) {
    int k = 0;
    Node *cur = list;
    Node *pos = num;
    
    while (pos != nullptr) {
        if (pos->data < 0) 
            k = (k + 10 + pos->data) % 10;
        else 
            k = (k + pos->data) % 10;

        for (int i = 0; i < k; i++)
            cur = cur->pNext; 
            
        cout << cur->data << " ";
        cur = list; 
        pos = pos->pNext;
    }
} 

void delete_list(Node *&pHead) {
    while (pHead != nullptr) {
        Node *tmp = pHead;
        pHead = pHead->pNext; 
        delete tmp;
    }
}