n = int(input())


outputdebug = False


def debug(msg):
    if outputdebug:
        print(msg)


class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.height = -1


class AVLTree:
    def __init__(self, *args):
        self.node = None
        self.height = -1
        self.balance = 0

        if len(args) == 1:
            for i in args[0]:
                self.insert(i)

    def height(self):
        if self.node:
            return self.node.height
        else:
            return 0

    def is_leaf(self):
        return self.height == 0

    def insert(self, key):
        tree = self.node
        newnode = Node(key)
        # empty tree일 경우에만 새 값을
        # empty tree의 루트(node)에 넣음
        # 이 루트의 left/right에 새 empty tree 선언
        if tree == None:
            self.node = newnode
            self.node.left = AVLTree()
            self.node.right = AVLTree()
            debug("Inserted key [" + str(key) + "]")

        # 현재 보고 있는 node가 비어있지 않고
        # 새 값이 현재 node의 값보다 작으면
        # 왼쪽 서브트리에 삽입 (재귀함수 호출)
        elif key < tree.key:
            self.node.left.insert(key)

        # 새 값이 현재 node의 값보다 크면
        # 오른쪽 서브트리에 삽입 (재귀함수 호출)
        elif key > tree.key:
            self.node.right.insert(key)

        else:
            debug("Key [" + str(key) + "] already in tree.")

        # rebalancing
        self.rebalance()

    def rebalance(self):
        """
        Rebalance a particular (sub)tree
        """
        # key inserted. Let's check if we're balanced
        self.update_heights(False)
        self.update_balances(False)
        while self.balance < -1 or self.balance > 1:
            if self.balance > 1:
                if self.node.left.balance < 0:
                    self.node.left.lrotate()  # we're in case II
                    self.update_heights()
                    self.update_balances()
                self.rrotate()
                self.update_heights()
                self.update_balances()

            if self.balance < -1:
                if self.node.right.balance > 0:
                    self.node.right.rrotate()  # we're in case III
                    self.update_heights()
                    self.update_balances()
                self.lrotate()
                self.update_heights()
                self.update_balances()

    def rrotate(self):
        # Rotate left pivoting on self
        debug("Rotating " + str(self.node.key) + " right")
        A = self.node
        B = self.node.left.node
        T = B.right.node

        self.node = B
        B.right.node = A
        A.left.node = T

    def lrotate(self):
        # Rotate left pivoting on self
        debug("Rotating " + str(self.node.key) + " left")
        A = self.node
        B = self.node.right.node
        T = B.left.node

        self.node = B
        B.left.node = A
        A.right.node = T

    def update_heights(self, recurse=True):
        if not self.node == None:
            if recurse:
                if self.node.left != None:
                    self.node.left.update_heights()
                if self.node.right != None:
                    self.node.right.update_heights()

            self.height = max(self.node.left.height, self.node.right.height) + 1
        else:
            self.height = -1

    def update_balances(self, recurse=True):
        if not self.node == None:
            if recurse:
                if self.node.left != None:
                    self.node.left.update_balances()
                if self.node.right != None:
                    self.node.right.update_balances()

            self.balance = self.node.left.height - self.node.right.height
        else:
            self.balance = 0

    def delete(self, key):
        # debug("Trying to delete at node: " + str(self.node.key))
        if self.node != None:
            if self.node.key == key:
                debug("Deleting ... " + str(key))
                if self.node.left.node == None and self.node.right.node == None:
                    self.node = None  # leaves can be killed at will
                # if only one subtree, take that
                elif self.node.left.node == None:
                    self.node = self.node.right.node
                elif self.node.right.node == None:
                    self.node = self.node.left.node

                # worst-case: both children present. Find logical successor
                else:
                    replacement = self.logical_successor(self.node)
                    if replacement != None:  # sanity check
                        debug(
                            "Found replacement for "
                            + str(key)
                            + " -> "
                            + str(replacement.key)
                        )
                        self.node.key = replacement.key

                        # replaced. Now delete the key from right child
                        self.node.right.delete(replacement.key)

                self.rebalance()
                return
            elif key < self.node.key:
                self.node.left.delete(key)
            elif key > self.node.key:
                self.node.right.delete(key)

            self.rebalance()
        else:
            return

    def logical_predecessor(self, node):
        """
        Find the biggest valued node in LEFT child
        """
        node = node.left.node
        if node != None:
            while node.right != None:
                if node.right.node == None:
                    return node
                else:
                    node = node.right.node
        return node

    def logical_successor(self, node):
        """
        Find the smallese valued node in RIGHT child
        """
        node = node.right.node
        if node != None:  # just a sanity check

            while node.left != None:
                debug("LS: traversing: " + str(node.key))
                if node.left.node == None:
                    return node
                else:
                    node = node.left.node
        return node

    def check_balanced(self):
        if self == None or self.node == None:
            return True

        # We always need to make sure we are balanced
        self.update_heights()
        self.update_balances()
        return (
            (abs(self.balance) < 2)
            and self.node.left.check_balanced()
            and self.node.right.check_balanced()
        )

    def inorder_traverse(self):
        if self.node == None:
            return []

        inlist = []
        l = self.node.left.inorder_traverse()
        for i in l:
            inlist.append(i)

        inlist.append(self.node.height)

        l = self.node.right.inorder_traverse()
        for i in l:
            inlist.append(i)

        return inlist

    def display(self, level=0, pref=""):
        """
        Display the whole tree. Uses recursive def.
        TODO: create a better display using breadth-first search
        """
        self.update_heights()  # Must update heights before balances
        self.update_balances()
        if self.node != None:
            print(
                "-" * level * 2,
                pref,
                self.node.key,
                "[" + str(self.height) + ":" + str(self.balance) + "]",
                ("L" if self.is_leaf() else " "),
            )
            if self.node.left != None:
                self.node.left.display(level + 1, "<")
            if self.node.left != None:
                self.node.right.display(level + 1, ">")


a = AVLTree()

for _ in range(1, n):
    target = int(input())
    a.insert(target)
print(a.inorder_traverse())

# print(print((a.inorder_traverse())))

# class Node:
#     def __init__(self, id):
#         self.id = id
#         self.leftchild = None
#         self.rightchild = None
#         self.height = 0


# def insert(node, id, height):
#     height += 1
#     if id < node.id:
#         if node.leftchild:
#             insert(node.leftchild, id, height)
#         else:
#             g[id].height = height
#             node.leftchild = g[id]
#     else:
#         if node.rightchild:
#             insert(node.rightchild, id, height)
#         else:
#             g[id].height = height
#             node.rightchild = g[id]

# root = g[int(input())]
# for _ in range(1, n):
#     insert(root, int(input()), 1)
# height_list = [v.height for k, v in g.items()]
# print(sum(height_list) + 1)

# g = {}
# for i in range(n):
#     g[i] = -1


"""
list lower bound insert logn +n
"""
# def lowerbound(array, target):
#     start, end = 0, len(array)
#     while start < end:
#         mid = (start + end) // 2
#         if target <= array[mid]:
#             end = mid
#         else:
#             start = mid + 1
#     return start


# root = int(input())
# g[root] = 1
# array = [root]
# for _ in range(1, n):
#     target = int(input())
#     start = lowerbound(array, target)
#     if start - 1 < 0:
#         height = g[array[start]]
#     elif start > len(array) - 1:
#         height = g[array[start - 1]]
#     else:
#         height = max(g[array[start - 1]], g[array[start]])
#     array.insert(start, target)
#     g[target] = height + 1


"""
binary search tree

"""


# print(sum(g.values()))
