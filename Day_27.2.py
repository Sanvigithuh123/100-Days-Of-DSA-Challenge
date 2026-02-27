'''
# node class:

class Node:
    def __init__(self,val):
        self.next=None
        self.data=val

'''

class Solution:
    def removeLoop(self, head):
        slow, fast = head, head
        prev = None
        while fast and fast.next:
            prev = slow
            slow = slow.next
            fast = fast.next.next
            
            if slow == fast:
            
                while slow != head:
                    prev = slow
                    slow = slow.next
                    head = head.next
                
                prev.next = None
