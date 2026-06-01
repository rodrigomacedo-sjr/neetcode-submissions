# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        i = 0
        curr = head
        first = True
        prevend = None

        while curr:
            end = None
            start = None
            while curr and i < k:
                if i == 0:
                    start = curr
                end = curr
                curr = curr.next
                i += 1

            if i < k:
                break

            prev = curr
            node = start
            temp = None
            while node and node != curr:
                temp = node.next 
                node.next = prev
                prev = node
                node = temp

            if first:
                head = end
                first = False
            else:
                prevend.next = end
            
            prevend = start

            i = 0

        return head