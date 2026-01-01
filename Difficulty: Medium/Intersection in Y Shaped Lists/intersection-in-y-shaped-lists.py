'''
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

'''

class Solution:
    def intersectPoint(self, head1, head2):
# Calculate length of first list
        len1 = 0
        temp = head1
        while temp:
            len1 += 1
            temp = temp.next
        
        # Calculate length of second list
        len2 = 0
        temp = head2
        while temp:
            len2 += 1
            temp = temp.next
        
        # Move the pointer of longer list by difference
        ptr1 = head1
        ptr2 = head2
        
        if len1 > len2:
            for _ in range(len1 - len2):
                ptr1 = ptr1.next
        else:
            for _ in range(len2 - len1):
                ptr2 = ptr2.next
        
        # Move both pointers until they meet
        while ptr1 != ptr2:
            ptr1 = ptr1.next
            ptr2 = ptr2.next
        
        return ptr1