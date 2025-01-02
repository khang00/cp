import collections
import heapq
import math
from collections import deque, defaultdict, Counter
from dataclasses import dataclass, field
from functools import cache
from heapq import heappop, heappush, heapify
from itertools import count
from math import log10, floor

from typing import List, Deque, Tuple, Dict

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def main():
    n = int(input())
    a = [0] * n

    if n > 0:
        a = [int(it) for it in input().split(" ")]

    a.sort()
    def helper(left, right):
        if left > right:
            return None

        # always choose left middle node as a root
        p = (left + right) // 2

        # preorder traversal: node -> left -> right
        curr_root = TreeNode(a[p])
        curr_root.left = helper(left, p - 1)
        curr_root.right = helper(p + 1, right)
        return curr_root

    root = helper(0, n - 1)
    sum_all_leaf = 0
    def sum_leaf(curr):
        nonlocal sum_all_leaf
        if curr is None:
            return

        if curr.left is None and curr.right is None:
            sum_all_leaf += curr.val
            return

        sum_leaf(curr.left)
        sum_leaf(curr.right)
        return

    sum_leaf(root)
    print(sum_all_leaf)
    return

if __name__ == '__main__':
    main()