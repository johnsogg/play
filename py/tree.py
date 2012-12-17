class Tree:
    """A basic binary tree"""
    
    def __init__(self):
        self.root = None

    def insert(self, node):
        if (self.root == None):
            self.root = node
        else:
            self.root.insert(node)

    def bulk_insert(self, numbers):
        for i in numbers:
            n = Node(i)
            self.insert(n)

    def report(self):
        if (self.root != None):
            self.root.report()
        else:
            print "No data"

    def contains(self, number):
        if (self.root != None):
            return self.root.contains(number)
        else:
            return false

class Node:
    """A node in the basic binary tree"""

    def __init__ (self, data):
        """Create a node"""
        self.data = data
        self.left = None
        self.right = None

    def insert(self, node):
        if (self.data > node.data):
            if (self.left == None):
                self.left = node
            else:
                self.left.insert(node)
        else:
            if (self.right == None):
                self.right = node
            else:
                self.right.insert(node)

    def report(self):
        if (self.left != None):
            self.left.report()
        print str(self.data)
        if (self.right != None):
            self.right.report()

    def contains(self, number):
        if (self.data == number):
            return True
        else:
            if (self.data > number):
                if (self.left != None):
                    return self.left.contains(number)
                else:
                    return False
            else:
                if (self.right != None):
                    return self.right.contains(number)
                else:
                    return False

if __name__ == '__main__':
    tree = Tree()
    tree.bulk_insert([4, 3, 6, 9, 13, 2, 3, 8, 3, 8, 4])
    tree.report()
    for i in range(1, 15):
        print str(i) + ": " + str(tree.contains(i))
    
