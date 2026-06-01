# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        group = []
        i = 0
        curr = head
        first = True
        prevend = None

        while curr:
            while curr and i < k:
                group.append(curr) 
                curr = curr.next
                i += 1

            if i < k:
                break

            prev = curr
            for node in group:
                node.next = prev
                prev = node

            if first:
                head = group[-1]
                first = False
            else:
                prevend.next = group[-1]
            
            prevend = group[0]

            group = []
            i = 0

        return head