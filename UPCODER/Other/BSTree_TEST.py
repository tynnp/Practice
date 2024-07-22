class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def insert(root, data):
    if root is None:
        return Node(data)
    if data < root.data:
        root.left = insert(root.left, data)
    elif data > root.data:
        root.right = insert(root.right, data)
    return root

def inOrder(root):
    if root is not None:
        inOrder(root.left)
        print(root.data, end=' ')
        inOrder(root.right)

def preOrder(root):
    if root is not None:
        print(root.data, end=' ')
        preOrder(root.left)
        preOrder(root.right)

def postOrder(root):
    if root is not None:
        postOrder(root.left)
        postOrder(root.right)
        print(root.data, end=' ')

n = int(input())
list = list(map(int, input().split()))
root = None
for tmp in list:
    root = insert(root, tmp)

inOrder(root)
print()

preOrder(root)
print()

postOrder(root)