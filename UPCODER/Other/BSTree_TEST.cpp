#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int data) {
    if (root == nullptr) 
        return new Node(data);
        
    if (data < root->data) 
        root->left = insert(root->left, data);
    else if (data > root->data) 
        root->right = insert(root->right, data);

    return root;
}

void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node* root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    int tmp, n;
    Node* root = nullptr;
    
    cin >> n;
    while (n--) {
        cin >> tmp; 
        root = insert(root, tmp);
    }

    // Left-Node-Right (Duyệt theo thứ tự)
    inOrder(root);
    cout << endl;

    // Node-Left-Right (Duyệt trước)
    preOrder(root);
    cout << endl;

    // Left-Right-Node (Duyệt sau)
    postOrder(root);
    return 0;
}