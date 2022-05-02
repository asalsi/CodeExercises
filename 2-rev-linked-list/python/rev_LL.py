'''
Python 2.7.12.
useful?
- import array, bisect, collections
for map/treemap: sortedcontainers
'''

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

### METHOD 1
# Class wrapping nodes, defining a linked list
class LList(object):
    def __init__(self):
        self.head = None

    # insertion method for the linked list
    def insert(self, val):
        newNode = ListNode(val)
        if(self.head):
            current = self.head
            while(current.next):
                current = current.next
            current.next = newNode
        else:
            self.head = newNode
    
    # print method for the linked list
    def printLL(self):
        current = self.head
        while(current):
            print(current.val)
            current = current.next
        print("\n")

    # reverse method
    def reverseList_it(self, head):
        curr = head
        prev = None
        while curr is not None:
            next_tmp = curr.next
            curr.next = prev
            if not next_tmp:
                break
            prev = curr
            curr = next_tmp
        self.head = curr
        # return curr

# Print list and reverse
LL = LList()
for i in range(4):
    LL.insert(i)
LL.printLL()
LL.reverseList_it(LL.head)
LL.printLL()

### METHOD 2 (https://www.geeksforgeeks.org/recursively-reversing-a-linked-list-a-simple-implementation/)
#### (w/out a class, more fun maybe)

# push to top of linked list
def push(head, new_data):
    node = ListNode(new_data)   # make new node
    node.val = new_data         # put data in
    node.next = head            # set next to current head (push)
    head = node                 # update head pointer
    return head

# print out vals following chain of SLL
def printLL(head):
    current = head
    while(current):
        print(current.val)
        current = current.next
    print("\n")

# reverse LL recursively
def reverse(node):

    # case of no node
    if (node == None):
        return node

    # last node - return as head (1st return)
    # start moving up call stack after this (line 97)
    if (node.next == None):
        return node

    # recursively call until base cases
    # in order of non-reversed list
    head = reverse(node.next)

    # reverse node pointers, moving up call stack
    # (or moving in reverse list order)
    node.next.next = node   # set next of node pushed just before curr to curr
    node.next = None        # set next of curr to None (get rid of non-rev'd link)
    return head

# Push LL sequence, print
head = None
head = push(head, 3)
head = push(head, 2)
head = push(head, 1)
head = push(head, 0)
printLL(head)

# Reverse and print
head = reverse(head)
printLL(head)