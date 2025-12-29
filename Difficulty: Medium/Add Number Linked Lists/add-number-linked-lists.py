'''
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
'''

class Solution:

    def addTwoLists(self, num1, num2):
        while num1 and num1.data == 0:
            num1 = num1.next
        while num2 and num2.data == 0:
            num2 = num2.next
        if num1 is None and num2 is None:
            return Node(0)
        
        def reverse(head):
            prev, node = None, head
            while node:
                node.next, node, prev = prev, node.next, node
            return prev
        
        node1, node2 = reverse(num1), reverse(num2)
        prev_sum_node, carry = None, 0
        while carry or node1 or node2:
            if node1:
                carry += node1.data
                node1 = node1.next
            if node2:
                carry += node2.data
                node2 = node2.next
            carry, sumi = divmod(carry, 10)
            sum_node = Node(sumi)
            sum_node.next, prev_sum_node = prev_sum_node, sum_node
        return prev_sum_node
        