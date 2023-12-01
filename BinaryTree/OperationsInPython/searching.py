class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None


def insert(node, key):
    if node == None:
        return Node(key)
        
    if (key < node.key):
        node.left = insert(node.left, key)
    elif(key > node.key):
        node.right = insert(node.right, key)
    
    return node
    
def search(node, key):
    if node is None or node.key == key:
        return node
    
    if node.key > key:
        return search(node.left, key)
    elif node.key > key:
        return search(node.right, key)

if __name__ == "__main__":
    root = None
    root = insert(root, 20)
    root = insert(root, 10)
    root = insert(root, 30)
    root = insert(root, 40)
    root = insert(root, 70)
    root = insert(root, 5)
    
    key = 10
    if search(root, key) is None:
        print(key, " Not Found")
    else:
        print(key, " Found")