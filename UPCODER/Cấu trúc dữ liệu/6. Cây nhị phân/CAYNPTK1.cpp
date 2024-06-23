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
    int info;
    Node *left;
    Node *right;
    Node(int value);
};

void insert(Node *&root, int value);
void print(Node *root);
void clear(Node *&root);

signed main() {
    fastIO;
    int n;
    Node *root = nullptr;
    
    while (cin >> n) 
        insert(root, n);
    
    print(root);
    clear(root);
    return 0;
} 

Node::Node(int value) {
    info = value;
    left = right = nullptr;
}

void insert(Node *&root, int value) {
    Node *node = new Node(value);
    
    if (root == nullptr) {
        root = node;
        return;
    }
    
    if (root->info == value) return;
    if (root->info > value) return insert(root->left, value);
    if (root->info < value) return insert(root->right, value);
}

void print(Node *root) {
    if (root == nullptr) return;
    if (root->left != nullptr) print(root->left);
    if (root->right != nullptr) print(root->right);
    cout << root->info << " ";
}

void clear(Node *&root) {
    if (root == nullptr) return;
    clear(root->left);
    clear(root->right);
    delete root;
}