import math
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        mid, curr = head, head
        while curr.next != None and curr.next.next != None:
            curr = curr.next.next
            mid = mid.next

        if curr.next != None:
            mid = mid.next

        pre, curr = None, mid
        while curr != None:
            temp = curr.next
            curr.next = pre

            pre = curr
            curr = temp

        curr = head
        while curr != mid:
            tc = curr.next
            curr.next = pre

            tp = pre.next
            pre.next = tc

            curr = tc
            pre = tp

        curr.next = None


if __name__ == '__main__':
    s = Solution()
    head = ListNode(1, ListNode(2, ListNode(3, ListNode(4))))
    s.reorderList(head)

